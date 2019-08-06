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


pending Building Finalizable Objects















