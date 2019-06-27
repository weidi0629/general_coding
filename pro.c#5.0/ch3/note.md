-- all data members and all methods must be contained within a type definition.

-- the class that defines the Main() method is termed the application object.

-- Environment class
  - 告诉你run main的参数
    - string[] theArgs = Environment.GetCommandLineArgs();
    - 多少盘符 Environment.GetLogicalDrives())
    - Environment.ProcessorCount; Environment.OSVersion; Environment.Version
    
-- Formatting Numerical Data
  - 不同字符不同含义，比如 c 是 currency, 完整的表 page 81
     - Console.WriteLine("c format: {0:c}", 99999);
  - string.Format() 也可以用的 
    - string userMessage = string.Format("100000 in hex is {0:x}",


pending System Data Types and Corresponding C# Keywords

