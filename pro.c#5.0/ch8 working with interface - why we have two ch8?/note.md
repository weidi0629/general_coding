-- Understanding Interface Types
  - a named set of abstract members

-- Interface Types vs. Abstract Base Classes
  - interface -- only abstract member definitions
  - an interface can be implemented by any class and structure 
  
-- defining custom interface 
  - all members are implicitly public and abstract 
  - 也可以定义property prototypes 
    - byte Points { get; }
    
-- Implementing an Interface
  - 申明的时候要把base class写在后面
  - 所有interface里的member都要申明
  - 把interface里申明的东西在class里定义具体的behavior就好  

-- Invoking Interface Members at the Object Level
  - how you know if a type support interface 
    - try/catch 
    
    - as keyword 
      - IPointy itfPt2 = hex2 as IPointy; IPointy 是个interface， 如果hex2不能转成interface, 那么itfPt2就是null
    
    - is keyword: return false 
      - if(myShapes[i] is IPointy)
    
    
   pending  Interfaces As Parameters
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
