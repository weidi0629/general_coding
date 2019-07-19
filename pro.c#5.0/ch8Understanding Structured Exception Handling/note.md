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


-- pending 

