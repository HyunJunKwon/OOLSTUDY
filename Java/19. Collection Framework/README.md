
# Collection Framework

### 배열과 컬렉션즈 프레임워크

* 배열에는 몇가지 불편한 점이 있었는데 그 중의 하나가 한번 정해진 배열의 크기를 변경할 수 없다는 점이다. 이러한 불편함을 컬렉션즈 프래임워크를 사용하면 줄어든다.

```	
package org.opentutorials.javatutorials.collection;
 
import java.util.ArrayList;
 
public class ArrayListDemo {
 
    public static void main(String[] args) {
        String[] arrayObj = new String[2];
        arrayObj[0] = "one";
        arrayObj[1] = "two";
        // arrayObj[2] = "three"; 오류가 발생한다.
        for(int i=0; i<arrayObj.length; i++){
            System.out.println(arrayObj[i]);
        }
         
        ArrayList al = new ArrayList();
        al.add("one");
        al.add("two");
        al.add("three");
        for(int i=0; i<al.size(); i++){
            System.out.println(al.get(i));
        }
    }
 
}
```

* 아래 코드처럼 배열은 그 크기를 한번 지정하면 크기보다 많은 수의 값을 저장할 수 없다.

```	
String[] arrayObj = new String[2];
arrayObj[0] = "one";
arrayObj[1] = "two";
// arrayObj[2] = "three"; 오류가 발생한다.
```

* 하지만 ArrayList는 크기를 미리 지정하지 않기 때문에 얼마든지 많은 수의 값을 저장할 수 있다.

```	
ArrayList al = new ArrayList();
al.add("one");
al.add("two");
al.add("three");
```

* ArrayList는 배열과는 사용방법이 조금 다르다. 배열의 경우 값의 개수를 구할 때 .length를 사용했지만 ArrayList는 메소드 size를 사용한다. 또한, 특정한 값을 가져올 때 배열은 [인덱스 번호]를 사용했지만 컬렉션은 .get(인덱스 번호)를 사용한다.

```
for(int i=0; i<al.size(); i++){
    System.out.println(al.get(i));
}
```

* 그런데 ArrayList를 사용할 때 주의할 점이 있다. 위의 반복문을 아래처럼 바꿔보자.

```	
for(int i=0; i<al.size(); i++){
    String val = al.get(i);
    System.out.println(val);
}
```

* 위의 코드는 컴파일 오류가 발생한다. ArrayList의 메소드 add의 입장에서는 인자로 어떤 형태의 값이 올지 알 수 없다. 그렇기 때문에 모든 데이터 타입의 조상인 Object 형식으로 데이터를 받고 있다. 예를들면 아래와 같은 모습일 것이다. (실제와는 다르다)
  * ```public boolean add(Object e) {```

* 따라서 ArrayList 내에서 add를 통해서 입력된 값은 Object의 데이터 타입을 가지고 있고, get을 이용해서 이를 꺼내도 Object의 데이터 타입을 가지고 있게 된다. 그래서 위의 코드는 아래와 같이 바꿔야 한다.

```	
for(int i=0; i<al.size(); i++){
    String val = (String)al.get(i);
    System.out.println(val);
}
```

* get의 리턴값을 문자열로 형변환하고 있다. 원래의 데이터 타입이 된 것이다. 그런데 위의 방식은 예전의 방식이다. 이제는 아래와 같이 제네릭을 사용해야 한다.

```	
ArrayList<String> al = new ArrayList<String>();
al.add("one");
al.add("two");
al.add("three");
for(int i=0; i<al.size(); i++){
    String val = al.get(i);
    System.out.println(val);
}
```

* 제네릭을 사용하면 ArrayList 내에서 사용할 데이터 타입을 인스턴스를 생성할 때 지정할 수 있기 때문에 데이터를 꺼낼 때(String val = al.get(i);) 형변환을 하지 않아도 된다.

### 컬렉션즈 프래임워크란?

* 컬렉션즈 프래임워크라는 것은 다른 말로는 컨테이너라고도 부른다. 즉 값을 담는 그릇이라는 의미이다. 그런데 그 값의 성격에 따라서 컨테이너의 성격이 조금씩 달라진다. 자바에서는 다양한 상황에서 사용할 수 있는 다양한 컨테이너를 제공하는데 이것을 컬렉션즈 프래임워크라고 부른다. ArrayList는 그중의 하나다.
* 그림참조
* Collection과 Map이라는 최상위 카테고리가 있고, 그 아래에 다양한 컬렉션들이 존재한다. 
* List와 Set의 차이점은 List는 중복을 허용하고, Set은 허용하지 않는다.

```	
package org.opentutorials.javatutorials.collection;
 
import java.util.ArrayList;
import java.util.HashSet;
 
import java.util.Iterator;
 
public class ListSetDemo {
 
    public static void main(String[] args) {
        ArrayList<String> al = new ArrayList<String>();
        al.add("one");
        al.add("two");
        al.add("two");
        al.add("three");
        al.add("three");
        al.add("five");
        System.out.println("array");
        Iterator ai = al.iterator();
        while(ai.hasNext()){
            System.out.println(ai.next());
        }
         
        HashSet<String> hs = new HashSet<String>();
        hs.add("one");
        hs.add("two");
        hs.add("two");
        hs.add("three");
        hs.add("three");
        hs.add("five");
        Iterator hi = hs.iterator();
        System.out.println("\nhashset");
        while(hi.hasNext()){
            System.out.println(hi.next());
        }
    }
 
}
```

* 결과는 아래와 같다.

```
array
one
two
two
three
three
five
 
hashset
two
five
one
three
```

* 우선 값을 가져오는 방법이 조금 달라졌다. (ArrayList에서도 이 방법을 사용할 수 있다)

```	
Iterator ai = al.iterator();
while(ai.hasNext()){
    System.out.println(ai.next());
}
```

* 메소드 iterator는 인터페이스 Collection에 정의되어 있다. 따라서 Collection을 구현하고 있는 모든 컬렉션즈 프레임웍크는 이 메소드를 구현하고 있음을 보증한다. 메소드 iterator의 호출 결과는 인터페이스 iterator를 구현한 객체를 리턴한다. 인터페이스 iterator는 아래 3개의 메소드를 구현하도록 강제하고 있는데 각각의 역할은 아래와 같다.
  * hasNext
    * 반복할 데이터가 더 있으면 true, 더 이상 반복할 데이터가 없다면 false를 리턴한다.
  * next
    * hasNext가 true라는 것은 next가 리턴할 데이터가 존재한다는 의미다. 
  * 이러한 기능을 조합하면 for 문을 이용하는 것과 동일하게 데이터를 순차적으로 처리할 수 있다.



### Set

* Set은 한국어로 집합이라는 뜻이다. 여기서의 집합이란 수학의 집합과 같은 의미다. 수학에서의 집합도 순서가 없고 중복되지 않는 특성이 있다는 것이 기억날 것이다. (기억나지 않아도 상관없다) 수학에서 집합은 교집합(intersect), 차집합(difference), 합집합(union)과 같은 연산을 할 수 있었다. Set도 마찬가지다.

```	
package org.opentutorials.javatutorials.collection;
 
import java.util.ArrayList;
import java.util.HashSet;
 
import java.util.Iterator;
 
public class SetDemo {
 
    public static void main(String[] args) {
        HashSet<Integer> A = new HashSet<Integer>();
        A.add(1);
        A.add(2);
        A.add(3);
         
        HashSet<Integer> B = new HashSet<Integer>();
        B.add(3);
        B.add(4);
        B.add(5);
         
        HashSet<Integer> C = new HashSet<Integer>();
        C.add(1);
        C.add(2);
         
        System.out.println(A.containsAll(B)); // false
        System.out.println(A.containsAll(C)); // true
         
        //A.addAll(B);
        //A.retainAll(B);
        //A.removeAll(B);
         
        Iterator hi = A.iterator();
        while(hi.hasNext()){
            System.out.println(hi.next());
        }
    }
 
}
```

### 부분집합 (subset)

```	
System.out.println(A.containsAll(B)); // false
System.out.println(A.containsAll(C)); // true
```
* 합집합(union)
```A.addAll(B);```

* 교집합(intersect)
```A.retainAll(B);```

* 차집합(difference)
```A.removeAll(B);```

### Map

* Map 컬렉션은 key와 value의 쌍으로 값을 저장하는 컬렉션이다.

```	
package org.opentutorials.javatutorials.collection;
 
import java.util.*;
 
public class MapDemo {
 
    public static void main(String[] args) {
        HashMap<String, Integer> a = new HashMap<String, Integer>();
        a.put("one", 1);
        a.put("two", 2);
        a.put("three", 3);
        a.put("four", 4);
        System.out.println(a.get("one"));
        System.out.println(a.get("two"));
        System.out.println(a.get("three"));
         
        iteratorUsingForEach(a);
        iteratorUsingIterator(a);
    }
     
    static void iteratorUsingForEach(HashMap map){
        Set<Map.Entry<String, Integer>> entries = map.entrySet();
        for (Map.Entry<String, Integer> entry : entries) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }
     
    static void iteratorUsingIterator(HashMap map){
        Set<Map.Entry<String, Integer>> entries = map.entrySet();
        Iterator<Map.Entry<String, Integer>> i = entries.iterator();
        while(i.hasNext()){
            Map.Entry<String, Integer> entry = i.next();
            System.out.println(entry.getKey()+" : "+entry.getValue());
        }
    }
 
}
```

* Map에서 데이터를 추가할 때 사용하는 API는 put이다. put의 첫번째 인자는 값의 key이고, 두번째 인자는 key에대한 값이다. key를 이용해서 값을 가져올 수 있다.
  * ```System.out.println(a.get("one"));```

* Map에 저장된 데이터를 열거할 때
```
Set<Map.Entry<String, Integer>> entries = map.entrySet();
for (Map.Entry<String, Integer> entry : entries) {
    System.out.println(entry.getKey() + " : " + entry.getValue());
}
```

* 메소드 entrySet은 Map의 데이터를 담고 있는 Set을 반환한다. 반환한 Set의 값이 사용할 데이터 타입은 Map.Entry이다. Map.Entry는 인터페이스인데 아래와 같은 API를 가지고 있다.
  * getKey
  * getValue
  * 위의 API를 이용해서 Map의 key, value를 조회할 수 있다.


* 컬렉션을 사용할 때는 데이터 타입은 가급적 해당 컬렉션을 대표하는 인터페이스를 사용하는 것이 좋다. 이전 예제의 12행의 내용은 아래와 같다.
  * ```HashMap<String, Integer> a = new HashMap<String, Integer>();```

* 이것을 아래와 같이 수정한다. HashMap은 Map 인터페이스를 구현하기 때문에 변수 a의 데이터 타입으로 Map을 사용할 수 있다.
  * ```Map<String, Integer> a = new HashMap<String, Integer>();```

* 어떤 필요에 의해서 컬렉션을 HashMap에서 HashTable로 바꾸고 싶다면 아래와 같이 수정하면 된다.
  * ```Map<String, Integer> a = new Hashtable<String, Integer>();```

### 정렬

* 컬렉션을 사용하는 이유 중의 하나는 정렬과 같은 데이터와 관련된 작업을 하기 위해서다. 

```
package org.opentutorials.javatutorials.collection;
 
import java.util.*;
 
class Computer implements Comparable{
    int serial;
    String owner;
    Computer(int serial, String owner){
        this.serial = serial;
        this.owner = owner;
    }
    public int compareTo(Object o) {
        return this.serial - ((Computer)o).serial;
    }
    public String toString(){
        return serial+" "+owner;
    }
}
 
public class CollectionsDemo {
     
    public static void main(String[] args) {
        List<Computer> computers = new ArrayList<Computer>();
        computers.add(new Computer(500, "egoing"));
        computers.add(new Computer(200, "leezche"));
        computers.add(new Computer(3233, "graphittie"));
        Iterator i = computers.iterator();
        System.out.println("before");
        while(i.hasNext()){
            System.out.println(i.next());
        }
        Collections.sort(computers);
        System.out.println("\nafter");
        i = computers.iterator();
        while(i.hasNext()){
            System.out.println(i.next());
        }
    }
 
}
/*
결과
before
500 egoing
200 leezche
3233 graphittie
 
after
200 leezche
500 egoing
3233 graphittie
*/
```

* 클래스 Collectors는 다양한 클래스 메소드를 가지고 있다. 메소드 sort는 그 중의 하나로 List의 정렬을 수행한다. 다음은 sort의 시그니처다.
  * ```public static <T extends Comparable<? super T>> void sort(List<T> list)```

* sort의 인자인 list는 데이터 타입이 List이다. 즉 메소드 sort는 List 형식의 컬렉션을 지원한다는 것을 알 수 있다. 인자 list의 제네릭 <T>는 coparable을 extends 하고 있어야 한다. Comparable은 인터페이스인데 이를 구현하고 있는 클래스는 아래 메소드를 가지고 있어야 한다.
  * ```compareTo(T o)```

* 아래의 메소드는 이러한 제약 조건을 준수하기 위해서 구현한 메소드다.
```
public int compareTo(Object o) {
    return this.serial - ((Computer)o).serial;
}
```

* 메소드 sort를 실행하면 내부적으로 compareTo를 실행하고 그 결과에 따라서 객체의 선후 관계를 판별하게 된다.

