# Abstract

### abstract

* abstract란 한국어로는 추상으로 번역된다. 이에 대한 정의는 뒤에서 내리도록 하고 지금 단계에서는 abstract라는 것이 상속을 강제하는 일종의 규제라고 생각하자. 즉 abstract 클래스나 메소드를 사용하기 위해서는 반드시 상속해서 사용하도록 강제하는 것이 abstract다. 

### 추상 메소드

* 추상 메소드란 메소드의 시그니처만이 정의된 비어있는 메소드를 의미한다. 아래의 코드를 보자.

```
package org.opentutorials.javatutorials.abstractclass.example1;
abstract class A{
    public abstract int b();
    //본체가 있는 메소드는 abstract 키워드를 가질 수 없다.
    //public abstract int c(){System.out.println("Hello")}
    //추상 클래스 내에는 추상 메소드가 아닌 메소드가 존재 할 수 있다. 
    public void d(){
        System.out.println("world");
    }
}
public class AbstractDemo {
    public static void main(String[] args) {
        A obj = new A();
    }
}
```

* 위 코드의 실행 결과는 아래와 같다.

```	
Exception in thread "main" java.lang.Error: Unresolved compilation problem: 
    Cannot instantiate the type A
    at org.opentutorials.javatutorials.abstractclass.example1.AbstractDemo.main(AbstractDemo.java:7)
```

* 메소드 b의 선언 부분에는 abstract라는 키워드가 등장하고 있다. 이 키워드는 메소드 b는 메소드의 시그니처만 정의 되어 있고 이 메소드의 구체적인 구현은 하위 클래스에서 오버라이딩 해야 한다는 의미다. 이렇게 내용이 비어있는 메소드를 추상 메소드라고 부른다. 추상 메소드를 하나라도 포함하고 있는 클래스는 추상 클래스가 되고, 자연스럽게 클래스의 이름 앞에 abstract가 붙는다. 

```
abstract class A{
    public abstract int b();
}
```

* 아래 코드는 오류를 발생시키는데 본체인 {System.out.println("Hello")}가 존재하는데 추상 메소드를 의미하는 abstract를 사용하고 있기 때문이다.

```public abstract int c(){System.out.println("Hello")}``` 

* 추상 클래스에는 추상 메소드가 아닌 메소드가 존재할 수 있다.

```	
public int d(){
    System.out.println("world");
}
```

* ```A obj = new A();```와 같이 추상 클래스 A를 인스턴스화하면 오류가 발생한다. 그것은 추상 클래스는 구체적인 메소드의 내용이 존재하지 않기 때문에 인스턴스화시켜서 사용할 수 없기 때문이다. 그럼 어떻게 해야 클래스 A를 사용할 수 있을까? 또 이렇게 불편한 추상 클래스는 왜 사용하는 것일까?	


### 추상 클래스의 상속

* 위의 문제를 해결하기 위해서는 클래스 A를 상속한 하위 클래스를 만들고 추상 메소드를 오버라이드해서 내용있는 메소드를 만들어야 한다. 아래 코드를 보자.

```
package org.opentutorials.javatutorials.abstractclass.example2;
abstract class A{
    public abstract int b();
    public void d(){
        System.out.println("world");
    }
}
class B extends A{
    public int b(){return 1;}
}
public class AbstractDemo {
    public static void main(String[] args) {
        B obj = new B();
        System.out.println(obj.b());
    }
}
```

* 클래스 B는 클래스 A를 상속했다. 그리고 클래스 A의 추상 메소드인 메소드 b를 오버라이딩하고 있다. 그 결과 클래스 A를 사용할 수 있었다.

### 추상 클래스를 사용하는 이유

* 추상 클래스는 상속을 강제하기 위한 것이다. 즉 부모 클래스에는 메소드의 시그니처만 정의해놓고 그 메소드의 실제 동작 방법은 이 메소드를 상속 받은 하위 클래스의 책임으로 위임하고 있다. 사실 코드를 이런 식으로 작성하는 경우는 작은 규모의 프로젝트에서는 거의 없다. 상황에 따라서 동작 방법이 달라지는 메소드는 추상 메소드로 만들어서 하위 클래스에서 구현하도록 하고 모든 클래스의 공통분모의 경우에는 상위 클래스에 두어서 코드의 중복, 유지보수의 편의성 등을 꾀할 수 있다.


### 디자인 패턴

* 템플릿은 모양을 결정하지만 템플릿을 통해서 그려질 도형은 팬의 종류나 색상에 따라서 달라진다. 즉 공통분모인 메소드 run은 메소드 sum과 avg가 어떻게 동작할지 알 수 없지만 sum이 실행되고 avg을 실행시킨다. 반면에 실행결과를 어떤 기호(+,-)로 시작할지는 하위 클래스에서 결정하고 있다.
즉, 위의 예제를 통해서도 알 수 있지만 프로그래밍이라는 것은 반복되는 패턴이 있다. 이런 패턴들을 모아서 정리한 것이 디자인 패턴(design pattern)이다. 물론 시각 디자이너들의 디자인이 아니라 좋은 소프트웨어를 만들기 위한 설계로서 디자인이라는 표현을 쓰고 있는 것이다. 디자인 패턴의 장점은 크게 두가지이다. 하나는 좋은 설계를 단기간에 학습할 수 있다는 점이다. 물론 비교적 단기간이라는 뜻이다. 다른 하나는 소통에 도움이 된다는 점이다. 설계 방법을 토의하거나 전달할 때 설계 방법에 따라 적절한 이름이 있다면 상호간에 생각을 일치시키는 데 큰 도움이 될 것이다.

