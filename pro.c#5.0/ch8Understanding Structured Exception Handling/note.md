-- The System.Exception Base Class
  - All exceptions ultimately derive from the System.Exception base class
  
-- The TargetSite Property
  - return type, name, and parameter types of the method 运行这个exception方程的性质
  
-- System-Level Exceptions (System.SystemException)
  - 不用自己建立一个完全是新的 exception class 
  - 可以分辨到底是system level exception 还是 application level 

-- Application-Level Exceptions (System.ApplicationException) Given that
  - the only purpose of System.ApplicationException is to identify the source of the error. code出问题了。 

-- Building Custom Exception 
  - generally should defined as public 
  - 自己新建一个exception的class。主要用在exceptoin时需要用到一些detailed的信息  

- Building Custom Exceptions, Take Two 
  - pass the error msg to parent class constructor 
    - public class CarIsDeadException : ApplicationException
      { ... public CarIsDeadException(string message, string cause, DateTime time):base(message)
  - 一般都会用这章这个例子   

-- Building Custom Exceptions, Take Three
  - 看下这章的一堆要求 


-- handling multiple exceptions 
  - will be processed by the "first available" catch 
    - make sure the first catch is most specific one

--General catch Statements
  - 直接加 catch, 没有特别的指定 ex种类，是非常general的方法 
  
-- Rethrowing Exceptions
  - throw 在catch block里面 
  
-- Inner Exceptions
  - 在处理ex时又出现ex-- 重新建立一个跟原来一样ex，重新throw 
  
-- finally Block
  - a set of code statements will always execute
  
  
  
  
  
