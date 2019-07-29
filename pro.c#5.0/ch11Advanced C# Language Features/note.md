-- Understanding Indexer Methods
  -- useful when you are creating custom collection classes
    - 想要的效果就是可以这样用：
      - myPeople[0] = new Person("Homer", "Simpson", 40);
      - myPeople是个PersonCollection的instance
  
  - 定义方法
    - public Person this[int index]
    
  -- 一般用已经定义好的类似与 List的组件就行 
  
  -- 还可以定义 string indexer and multiple dimensions indexer 
  
  
  -- understanding operator overloading 
    - 跟c++差不多
    
  -- Understanding Custom Type Conversions
    - Base and Derived classes are related by classical inheritance
    
    -- () casting operator?
        - public static explicit operator Square(Rectangle r) -- explicit keywords 
        - must be static 
        - 用法： Square s = (Square)r;
        
    -- if you have a structure, which makes use of automatic property syntax (as we do here), the default constructor must be explicitly called
  
  pengding 
  Additional Explicit Conversions for the Square Type
  
  
  
  
