-- Nongeneric collections
  - working on System.Object, loosely type

-- Generic collections
  - need to specify 'type of type'

-- The Problems of Nongeneric Collections

  -- performance
    - 题外话： stack heap的区别
      - stack 是放local variable，跟 algorithm里的stack不一样
      - heap 是放obj的，几个obj可以share data

    - boxing - box the value type into a ref type 
      - object boxedInt = myInt;

    - ArrayList is operating on object, so boxing/unboxing 好几次 
    
  -- The Issue of Type Safety
  
    - ArrayList 什么东西都可以加进去, 如果要保证container里面都要一样的type, 必须自己constomize一个class 
  
--   A First Look at Generic Collections
  -- use the generic version interface IComparable<T>
  
  
-- The System.Collections.ObjectModel Namespace
  
  -- Working with ObservableCollection<T>
     - CollectionChanged will fire whenever a new item is inserted, a current item is removed (or relocated), or if the entire collection is modified.
     - public enum NotifyCollectionChangedAction 定义哪个action
     - NotifyCollectionChangedEventArgs has two important properties: OldItems and NewItems.
  
  
  pending page 341 
