-- Defining Custom Namespaces 
   -  Resolve the ambiguity using a custom alias.
      - e.g. using The3DHexagon = My3DShapes.Hexagon;
  
-- The Role of .NET Assemblies 
   - file extensions (*.exe or *.dll)
   - a referenced *.exe can also be considered a code library
  
-- GAC global assembly cache 
  - 几个app一起要用的assembly
  
-- Understanding the Format of a .NET Assembly  
  - The Windows File Header
  - The CLR File Header
    - 以上这两个不是很重要
  
  - CIL Code, Type Metadata, and the Assembly Manifest
  
    -- Building a C# Client Application
      - need add 'using CarLibrary;' in the client application 
  
-- Configuring Private Assemblies
   - a *.config 告诉application要去哪里找 
  
  -- Understanding Shared Assemblies
      - 就好像 mscorlib.dll一样，所有app都可以用 
  
      -- The Global Assembly Cache
         - GAC 文件夹里都是装shared 文件
            - 4.0 and higher 是放在 C:\Windows\Microsoft.NET\assembly\GAC_MSIL
  
  - pending understanding strong names 
  
  
  
