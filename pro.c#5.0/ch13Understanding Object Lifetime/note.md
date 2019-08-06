-- the new keyword returns a reference to the object on the heap, not the actual object itself.

-- Setting Object References to null
  - 只是整个ref 不指向heap中任一的obj
  - 但不意味着 fire up at that exact moment and remove the object from the heap
  
-- Understanding Object Generations
  - the longer an object has existed on the heap, the more likely it is to stay there
    - gen1 比 gen0 survive more round of garbage collection 
    
-- Force garbage collection 
  - 一般很少用，用的情况有:
    - Your application is about to enter into a block of code that you don’t want interrupted by a possible garbage collection.
    - Your application has just finished allocating an extremely large number of objects
and you want to remove as much of the acquired memory as soon as possible.

  - 用法  GC.Collect();
          GC.WaitForPendingFinalizers(); // perform any necessary cleanup before your
program continues


-- Building Finalizable Objects  - only for unmanaged resources
  -- Finalize() 是定义protected，自己不能call. 要叫garbage collector来call
  
  -- OS file handles 也是需要主意clean up的

  -- 只有在用 unmanaged resources via PInvoke or complex COM interoperability task 才需要考虑

  -- Overriding System.Object.Finalize()
    ~MyResourceWrapper(){
      - 不能在里面写之前的obj，因为可能已经不在了

-- Building Disposable Objects
  - public interface IDisposable
    {
      void Dispose();
    }
  - the object user manually calls Dispose()
  
  - 定义class的时候就要include这个interface 
    - class MyResourceWrapper : IDisposable ... 
    - 可以check能不能call Dispose()
      - if (rw is IDisposable) 
    
  - it is perfectly safe to communicate with other managed objects within a Dispose() method
  
  - 就算有close，可能只是一个alias，call depose更好
  
-- Reusing the C# using Keyword
  - 正常会把disaposable的obj 放在 try/catch/finally block里， using可以起到同样的办法
    - using(MyResourceWrapper rw = new MyResourceWrapper()) 会在底层call Disapose()
  
  - 还可以连续call几个
    using(MyResourceWrapper rw = new MyResourceWrapper(), rw2 = new MyResourceWrapper())
  
  - GC.SuppressFinalize(this); 放在dispose里面，告诉garbage collector不用collect 这个了  

-- A Formalized Disposal Pattern
   传一个bool进去，具体pattern看page 484
    
-- Understanding Lazy Object Instantiation    
    - 只有在真的用的时候才会真的assign memory 
    - private Lazy<AllTracks> allSongs = new Lazy<AllTracks>();
    
    - Customizing the Creation of the Lazy Data
      - generic delegate or lambda 
        - 
    
    
    
    
    
    
    
    
    
    
    
    
    







