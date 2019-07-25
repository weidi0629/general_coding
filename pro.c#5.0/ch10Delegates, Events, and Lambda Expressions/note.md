-- Understanding the .NET Delegate Type
  - In essence, a delegate is a type-safe object that points to another method (or possibly a list of methods) in the application, 
    which can be invoked at a later time.
    - address/parameters/return type 
    
  - must define the delegate to match the signature of the method(s) it will point to
    - e.g. public delegate int BinaryOp(int x, int y);
          BinaryOp b = new BinaryOp(SimpleMath.Add);
          // Invoke Add() method indirectly using delegate object.
          Console.WriteLine("10 + 10 is {0}", b(10, 10));
          
          
pending Investigating a Delegate Object 
    
