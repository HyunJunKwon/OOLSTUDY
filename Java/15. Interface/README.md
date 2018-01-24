# Interface


### 인터페이스란?

* 인터페이스(interface)는 다소 추상적인 개념이다. 인터페이스를 abstract, final와 함께 대표적인 규제라고 언급했었다. 인터페이스의 역할은 이렇다. 어떤 객체가 있고 그 객체가 특정한 인터페이스를 사용한다면 그 객체는 반드시 인터페이스의  메소드들을 구현해야 한다. 만약 인터페이스에서 강제하고 있는 메소드를 구현하지 않으면 이 에플리케이션은 컴파일 조차 되지 않는다.

```	
package org.opentutorials.javatutorials.interfaces.example1;
 
interface I{
    public void z();
}
 
class A implements I{
    public void z(){}
}
```

* 클래스 A 뒤의 implements I는 이 클래스가 인터페이스 I를 구현하고 있다는 의미다. 그것은 3행의 interface I의 맴버인 public void z() 메소드를 클래스 A가 반드시 포함하고 있어야 한다는 뜻이다. 따라서 위의 코드는 문제가 없다. 인터페이스의 의미를 좀 더 분명하게 하기 위해서 8행의 public void z(){}를 삭제하자. 컴파일 에러가 발생할 것이다. 

* 인터페이스와 상속은 다르다. 상속이 상위 클래스의 기능을 하위 클래스가 물려 받는 것이라고 한다면, 인터페이스는 하위 클래스에 특정한 메소드가 반드시 존재하도록 강제한다. 이러한 규제가 왜 필요한지는 뒤에서 알아본다.

* 또 사용하는 키워드도 다르다. 클래스를 선언 할 때는 class를 사용하지만 인터페이스는 interface를 사용한다.

* 또 상속은 extends를 사용하지만 인터페이스는 implements를 사용한다. 이를 바탕으로 위의 예제를 해설해보면 아래와 같다.
  * 클래스 A는 인터페이스 I를 '구현' 한다.

### 실질적인 쓰임

* 계산기 예제에 인터페이스를 도입해보자. 계산기 기능이 필요한 프로젝트를 진행하는데 시간이 촉박하다. 그래서 계산기 클래스는 개발자 A가 만들고, 개발자 B는 그 클래스를 사용하는 로직을 만들다고 해보자. 이런 경우 개발자 B는 개발자 A가 계산기를 잘 만들어서 나중에 제출할 것이라고 기대하고 개발을 진행할 것이다. 그리고 아래와 같이 가짜 로직을 만들어서 코드를 작성했다.

```
package org.opentutorials.javatutorials.interfaces.example1;
class CalculatorDummy{
    public void setOprands(int first, int second, int third){}
    public int sum(){
        return 60;
    }
    public int avg(){
        return 20;
    }
}
public class CalculatorConsumer {
    public static void main(String[] args){
        CalculatorDummy c = new CalculatorDummy();
        c.setOprands(10,20,30);
        System.out.println(c.sum()+c.avg());
    }
}
```

* 개발자 A가 Calculator를 만드는데 3개월이 필요하다고 한다면 그 시간을 단축하기 위해서 위와 같은 코드를 작성하는 이유가 공감 할 수 있을 것이다. 3개월이 지나고 개발자 A가 Calculator 클래스를 완성해서 인계해줬다. 아래는 그 코드다.

```
package org.opentutorials.javatutorials.interfaces.example1;
 
class Calculator {
    int left, right;
    public void setOprands(int left, int right) {
        this.left = left;
        this.right = right;
    }
    public void sum() {
        System.out.println(this.left + this.right);
    }
    public void avg() {
        System.out.println((this.left + this.right) / 2);
    }
}
```
 
* class Calculator를 사용할 개발자가 이 클래스가 가지고 있어야 할 메소드를 인터페이스로 만들어서 제공하는 것이다. 반대의 경우도 가능하다. 만드는 쪽에서 인터페이스를 제공하면 된다. 양쪽의 개발자는 이 인터페이스를 구현한 클래스 Calculator와 CalculatorDummy를 각각 구현하면 된다.

* 이렇게 해서 만들어진 코드를 보자. 아래는 약속을 정의하고 있는 인터페이스이다.
```
package org.opentutorials.javatutorials.interfaces.example2;
 
public interface Calculatable {
    public void setOprands(int first, int second, int third) ;
    public int sum(); 
    public int avg();
}
```

* 다음은 인터페이스를 구현한 가짜 클래스를 임시로 사용해서 만든 에플리케이션이다.

```
package org.opentutorials.javatutorials.interfaces.example2;
class CalculatorDummy implements Calculatable{
    public void setOprands(int first, int second, int third){
    }
    public int sum(){
        return 60;
    }
    public int avg(){
        return 20;
    }
}
public class CalculatorConsumer {
    public static void main(String[] args) {
        CalculatorDummy c = new CalculatorDummy();
        c.setOprands(10, 20, 30);
        System.out.println(c.sum()+c.avg());
    }
}
```

* 다음 코드는 인터페이스에 따라서 구현된 클래스이다.

```
package org.opentutorials.javatutorials.interfaces.example2;
 
class Calculator implements Calculatable {
    int first, second, third;
    public void setOprands(int first, int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
    public int sum() {
        return this.first + this.second + this.third;
    }
    public int avg() {
        return (this.first + this.second + this.third) / 3;
    }
}
```
이제 해야 할 일은 가짜 클래스인 CalculatorDummy를 실제 로직으로 교체하면 된다.
```
package org.opentutorials.javatutorials.interfaces.example2;
public class CalculatorConsumer {
    public static void main(String[] args) {
        Calculator c = new Calculator();
        c.setOprands(10, 20, 30);
        System.out.println(c.sum()+c.avg());
    }
}
```

* 이렇게해서 인터페이스를 이용한 협업에 대해서 알아봤다. 인터페이스를 이용해서 서로가 동일한 메소드를 만들도록 규약을 만들어서 공유한 결과 각자가 상대의 일정이나 구현하는 방식에 덜 영향을 받으면서 에플리케이션을 구축 할 수 있었다.

### 인터페이스의 규칙

* 하나의 클래스가 여러개의 인터페이스를 구현 할 수 있다. 

* 클래스 A는 메소드 x나 z 중 하나라도 구현하지 않으면 오류가 발생한다.
```
package org.opentutorials.javatutorials.interfaces.example3;
 
interface I1{
    public void x();
}
 
interface I2{
    public void z();
}
 
class A implements I1, I2{
    public void x(){}
    public void z(){}   
}
```

* 인터페이스도 상속이 된다.

```
package org.opentutorials.javatutorials.interfaces.example3;
 
interface I3{
    public void x();
}
 
interface I4 extends I3{
    public void z();
}
 
class B implements I4{
    public void x(){}
    public void z(){}   
}
```

* 인터페이스의 맴버는 반드시 public이다.

* 아래 코드는 오류를 발생한다. 인터페이스는 그 인터페이스를 구현한 클래스를 어떻게 조작할 것인가를 규정한다. 그렇기 때문에 외부에서 제어 할 수 있는 가장 개방적인 접근 제어자인 public만을 허용한다. public을 생략하면 접근 제어자 default가 되는 것이 아니라 public이 된다. 왜냐하면 인터페이스의 맴버는 무조건 public이기 때문이다.

```
package org.opentutorials.javatutorials.interfaces.example3;
 
interface I5{
    private void x();
}
abstract vs interface
```

* 인터페이스와 추상 클래스는 서로 비슷한 듯 다른 기능이다. 인터페이스는 클래스가 아닌 인터페이스라는 고유한 형태를 가지고 있는 반면 추상 클래스는 일반적인 클래스다. 또 인터페이스는 구체적인 로직이나 상태를 가지고 있을 수 없고, 추상 클래스는 구체적인 로직이나 상태를 가지고 있을 수 있다.
