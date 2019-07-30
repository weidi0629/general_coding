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
  
    -- Defining Implicit Conversion Routines
      - public static implicit operator Rectangle(Square s)
  
  
 --  Understanding Extension Methods
     - they must be defined within a static class
     
     - using the this keyword as a modifier 指向你要改的class
     
     - if namespace is different, use the 'using' keywords
     
     - extension methods are not literally defined on the type being extended
     
     - VS 会提醒你哪些是ext method
     
     - 可以针对interface来定义extension
      - 所有用了这个interface的class都ext这个class
     
     
  -- Understanding Anonymous Types
     - 用处：只是定义一些名词变量，没有什么method之类
     - var + initialization synctax
       - var car = new { Make = make, Color = color, Speed = currSp };
       - 会自动在后台建立 private perpety 
     
     - anonymous type all derived from system.object, so all have Equals(), GetHashCode(), and ToString().
     
  -- working with pointer types 
    - 跟c++很像： * & -> etc. 
     
    -- 因为作者强烈建议不要用，所以跳过
    
    
