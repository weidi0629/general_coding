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
    
-- Interfaces As Parameters
    - interface is a valid .net type, can be used as parameter    
    - 注意，方程如果接受的parameter是interface，但传进去的是object
    
-- Interfaces As Return Values
  - 要把obj进行一个转换 return s as IPointy;
    
-- Arrays of Interface Types
  - 即使不同的class只要定义了一样的interface,就可以放在一个array里 
    
-- Explicit Interface Implementation
  - 因为class可以implement任意个数的interface，如果每个interface里的方程名字一样怎么办？
  - 明确表示：implement时
    - void IDrawToForm.Draw(){
          Console.WriteLine("Drawing to form...");
    - 不要加accesor，automatically private 
      - 不能再ojb时直接用 . 来call，要explicit cast 
        - ((IDrawToPrinter)oct).Draw();
  
-- Designing Interface Hierarchies
  -- 也可以inherits from existing interface
  -- can be useful when you want to extend the functionality of an existing interface without breaking existing code bases
  -- implement时从最下到最上都要implement     
  -- usage
    - obj level: myBitmap.DrawInBoundingBox(10, 10, 100, 150);
    - explict cast IAdvancedDraw iAdvDraw = myBitmap as IAdvancedDraw;
            
--Multiple Inheritance with Interface Types
  -- 直接定义: interface IShape : IDrawable, IPrintable
    - 现在因为三个里面都有draw(), 可以顶一个笼统的draw(), 也可以explict cast 
      - void IDrawable.Draw()
    
### 概念完了，现在说c#内置的interface ###

-- The IEnumerable and IEnumerator Interfaces
  - 只要implement GetEnumerator()的都可以用 foreach 
    - foreach 指向subitem
    - 可以一个个慢慢定义public interface IEnumerator里面所有的method,但最好delegate到array
      - return carArray.GetEnumerator();
    
  --  Building Iterator Methods with the yield Keyword
    - foreach (Car c in carArray{
        yield return c;
    

  -- Building a named interator
    - can take any number of arguments
      - public IEnumerable GetTheCars(bool ReturnRevesed)
    
    
--  The ICloneable Interface
    -- 一般class都是都是ref type， 如果要返回自身的一个value type怎么办 
      - public interface ICloneable{
          object Clone();
      - this.MemberwiseClone(); 是一个简单的做法，但是要保证member 里面没有ref(比如 class inside class)
      - 如果有的话： you might want to create a new object that takes into account each reference type member variable, in order to get a “deep copy.”
      
-- The IComparable Interface
  - 有这个就可以sort based on some specified key 
    - public interface IComparable{
        int CompareTo(object o);
        o.id > this.id return 1/0/-1
    - 可以利用member本身就有的CompareTo interface
      - return this.CarID.CompareTo(temp.CarID);

    -- Specifying Multiple Sort Orders with IComparer
      - interface IComparer{
          - int Compare(object o1, object o2);
      - 一般是用在helper class里面， 有点像C++里面的callerable     
        - Array.Sort(myAutos, new PetNameComparer());
        - 或者直接放在class 定义里面 
          - 定义时
            public static IComparer SortByPetName
                { get { return (IComparer)new PetNameComparer(); } }
          - 使用时
              Array.Sort(myAutos, Car.SortByPetName);


    
      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
