-- 整个delegate的意思就是。让某个class/obj 去跑，跑到某一个特定状态就运行一个程序做个特别的程序（最简单就是打在屏幕上）。 这个程序就叫callback。 

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

pending 381 Accessing Local Variables



