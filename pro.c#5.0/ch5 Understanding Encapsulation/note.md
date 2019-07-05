-- Allocating Objects with the new Keyword  
  - using new to allocate into memory
  - 如果只是单 decleare 一下，其实是 declares a reference to a yet-to-be-determined Carobject
    - Car myCar; 
  
-- Understanding Constructors
  - 如果define custom cont, 就一定要define default ctor 
  
  -- use this for constructor chain 
    - 一个总的constructor接受很多parameter. 少的通过this 传默认值进去
      - public Motorcycle(int intensity) 
          : this(intensity, "") {}
          - 最后控制还是回到这个 ctor
  

pending - Understanding the static Keyword - page 172






