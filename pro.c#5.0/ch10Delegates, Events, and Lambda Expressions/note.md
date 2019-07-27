-- 整个delegate的意思就是。让某个class/obj 去跑，跑到某一个特定状态就运行一个程序做个特别的程序（最简单就是打在屏幕上）。 这个程序就叫callback。
  - 可以想象class 有个修车功能，你就让他去修，你就是caller.修好了你可以叫他打个电话给你，‘打电话’就是callback，你自己定义。打电话可以换成发短信
    ，写邮件，寄平信，甚至是丢一泡屎过来

-- Understanding the .NET Delegate Type
  - In essence, a delegate is a type-safe object that points to another method (or possibly a list of methods) in the application, 
    which can be invoked at a later time.
    - address/parameters/return type 
    
  - must define the delegate to match the signature of the method(s) it will point to
    - e.g. public delegate int BinaryOp(int x, int y);
          BinaryOp b = new BinaryOp(SimpleMath.Add);
          // Invoke Add() method indirectly using delegate object.
          Console.WriteLine("10 + 10 is {0}", b(10, 10));
                 
-- Enabling Multicasting
  - maintain a list of method: 用 +=
    - 注册了两个，两个都会被call 
  
  - 一般这样注册就可以了 
    - c1.UnRegisterWithCarEngine(CallMeHere);

--The Generic Action<> and Func<> Delegates
  - 不在乎名字，只要两个delegate就可以了 
    - 区别是，Func是可以有返回的 
    
-- Understanding C# Events
  - event keyword 
    - registration and unregistration methods
    - always private 
    
  - 2 steps for using event   
    - 先建立一个 delegate
    - 再用event跟他建立联系 
    
-- Listening to Incoming Events

-- Creating Custom Event Arguments

-- The Generic EventHandler<T> Delegate
  - T 表示任意定义的type，也是系统做好的一个obj

-- Understanding C# Anonymous Methods
  - 就类似于直接定义。 定义结束后要加分号结束。 

-- Accessing Local Variables
  - 可以access outer local variable 
  
-- Understanding Lambda Expressions
  - System.Predicate<T> is a generic delegate of type, returning a bool and takes a single type paramters 

  - lambda even 可以不用显示出delegate的关键词
    -  List<int> evenNumbers = list.FindAll(i => (i % 2) == 0); // FindAll的参数其实是需要一个delycate的
    
  -- Dissecting a Lambda Expression
    - ArgumentsToProcess => StatementsToProcessThem
    - explicitly state
      - list.FindAll((int i) => (i % 2) == 0);
      
      - Processing Arguments Within Multiple Statements
        - 放进大括号里就可以了 
      
      - Lambda Expressions with Multiple (or Zero) Parameters
        - () => {return "Enjoy your string!";}
      
      
      
      
      
    
    
    

