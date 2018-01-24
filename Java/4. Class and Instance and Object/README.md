#  Class and Instance and Object

* 클래스와 인스턴스 이전의 프로그래밍	
```
public class CalculatorDemo { 
    public static void main(String[] args) {
        // 아래의 로직이 1000줄 짜리의 복잡한 로직이라고 가정하자.
        System.out.println(10 + 20);
        System.out.println(20 + 40);
    }
}
```

* 메소드화
```
실행 결과는 30과 60이다. 프로그래밍의 기본은 중복을 제거하는 것이다. 위의 로직은 두개의 값을 더한다는 중복이 존재한다. 
이 중복을 제거하기 위한 방법으로 고려해볼 수 있는 기능이 메소드다. 로직을 메소드로 만들면 코드의 양을 줄일 수 있고, 
문제가 생겼을 때 원인을 더 쉽게 찾을 수 있다.
public class CalculatorDemo2 {
    public static void sum(int left, int right) {
        System.out.println(left + right);
    }
    public static void main(String[] args) {
        sum(10, 20);
        sum(20, 40);
    } 
}
그런데 똑같은 수를 이용해서 더하기 뿐 아니라 평균도 구해야 한다면 어떻게 해야할까? 
아래와 같이 할 수 있을 것이다. 입력값(left, right)을 변수화시키고 메소드들(sum, avg)가 이 값을 사용하면 코드의 양을 줄일 수 있게 된다. 
public class ClaculatorDemo3 {
    public static void avg(int left, int right) {
        System.out.println((left + right) / 2);
    }
    public static void sum(int left, int right) {
        System.out.println(left + right);
    }
    public static void main(String[] args) {
        int left, right;
        left = 10;
        right = 20;
        sum(left, right);
        avg(left, right);
        left = 20;
        right = 40;
        sum(left, right);
        avg(left, right);
    }
}
```

* 객체화
	* 평균을 계산하는 메소드 avg를 추가했고, 두개의 메소드(sum, avg)에서 동일한 입력값(10, 20)을 사용하고 있기 때문에 변수를 이용해서 좌항(left)과 우항(right)에 값을 담았다. 코드가 복잡해지기 시작한다.
	* 객체 지향의 핵심은 연관되어 있는 변수와 메소드를 하나의 그룹으로 묶어서 그룹핑하는 것이다. 위의 예제를 분석해보자. 연관되어 있는 부분과 반복적인 부분을 찾아 볼 수 있다.
  * 메소드 sum과 avg는 변수 left와 right와 서로 연관 되어 있다. 또한 합계와 평균을 구하는 작업은 다른 에플리케이션에서도 사용할 수 있는 기능이다. 이것들을 그룹핑해서 하나의 부품으로 만들면 필요할 때마다 반복적으로 사용할 수 있을 것이다. 객체를 만들 때가 된 것이다.
```
class Calculator{
    int left, right;      
    public void setOprands(int left, int right){
        this.left = left;
        this.right = right;
    } 
    public void sum(){
        System.out.println(this.left+this.right);
    } 
    public void avg(){
        System.out.println((this.left+this.right)/2);
    }
} 
public class CalculatorDemo4 {     
    public static void main(String[] args) {
        Calculator c1 = new Calculator();
        c1.setOprands(10, 20);
        c1.sum();       
        c1.avg();       
        Calculator c2 = new Calculator();
        c2.setOprands(20, 40);
        c2.sum();       
        c2.avg();
    } 
}
```

* 클래스
	* 클래스는 연관되어 있는 변수와 메소드의 집합이다.

* 인스턴스
	* ```Calculator c1 = new Calculator();```
	* new Calculator()은 클래스 Calculator를 구체적인 제품으로 만드는 명령이다. 이렇게 만들어진 구체적인 제품을 인스턴스(instance)라고 부른다. 아래의 관계를 기억하자.
	* 클래스 : 설계도, 인스턴스 : 제품
	* 변수를 다른 말로는 상태(state)라고도 표현한다. c1.sum의 결과는 30, c2.sum의 결과는 60인 것을 통해서 알 수 있듯이 상태가 다른 객체를 대상으로 메소스를 실행시키면 다른 결과를 나타내게 된다. 메소드를 다른 말로는 행동(behave)라고도 표현한다.
	* 변수 : 상태, 메소드 : 행동
	* 즉 하나의 클래스를 바탕으로 서로 다른 상태를 가진 인스턴스를 만들면 서로 다른 행동을 하게 된다는 것을 알 수 있다. 하나의 클래스가 여러개의 인스턴스가 될 수 있다는 점이 객체 지향이 제공하는 가장 기본적인 재활용성이라고 할 수 있다.

<br/>

# 클래스 멤버와 인스턴스 멤버

* 맴버
	* 맴버(member)는 영어로 구성원이라는 뜻이다. 객체도 구성원이 있는데 아래와 같다.
	* 변수, 메소드

* 클래스 변수
```
class Calculator {
    static double PI = 3.14;
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
 
public class CalculatorDemo1 {
 
    public static void main(String[] args) {
 
        Calculator c1 = new Calculator();
        System.out.println(c1.PI);
 
        Calculator c2 = new Calculator();
        System.out.println(c2.PI);
 
        System.out.println(Calculator.PI);
 
    }
}
```
* static double PI = 3.14;
  * 변수 PI의 앞에 static이 붙었다. static을 맴버(변수,메소드) 앞에 붙이면 클래스의 맴버가 된다. 클래스 소속의 변수를 만드는 법을 알았으니까 이번에는 이것을 사용하는 법을 알아보자. 아래는 클래스 변수에 접근하는 방법 두가지를 보여준다.

```
// 인스턴스를 통해서 PI에 접근
System.out.println(c1.PI);
// 클래스를 통해서 PI에 접근
System.out.println(Calculator.PI);
```

* 두번째 방법은 객체 Calculator.java의 다른 기능(sum, avg)은 필요없고, 원주율만 필요할 때 클래스에 직접 접근하기 때문에 인스턴스를 생성할 필요가 없어진다.

* 클래스 변수는 변수의 변경사항을 모든 인스턴스에서 공유해야 할 때도 사용한다. 만약 계산을 할 때 특별한 값을 포함시켜야 한다면 어떻게 해야 할까? 
```
class Calculator2 {
    static double PI = 3.14;
    // 클래스 변수인 base가 추가되었다.
    static int base = 0;
    int left, right;
 
    public void setOprands(int left, int right) {
        this.left = left;
        this.right = right;
    }
 
    public void sum() {
        // 더하기에 base의 값을 포함시킨다.
        System.out.println(this.left + this.right + base);
    }
 
    public void avg() {
        // 평균치에 base의 값을 포함시킨다.
        System.out.println((this.left + this.right + base) / 2);
    }
}
 
public class CalculatorDemo2 {
 
    public static void main(String[] args) {
 
        Calculator2 c1 = new Calculator2();
        c1.setOprands(10, 20);
        // 30 출력
        c1.sum();
 
        Calculator2 c2 = new Calculator2();
        c2.setOprands(20, 40);
        // 60 출력
        c2.sum();
 
        // 클래스 변수 base의 값을 10으로 지정했다.
        Calculator2.base = 10;
 
        // 40 출력
        c1.sum();
 
        // 70 출력
        c2.sum();
 
    }
 
}

//*결과는 아래와 같다.	
30
60
40
70
*/
```
* 클래스 변수 base의 값을 변경한 결과 모든 인스턴스의 base 값이 일제히 변경되었다.

* 클래스 변수의 용도를 정리해보면 아래와 같다.
  * 인스턴스에 따라서 변하지 않는 값이 필요한 경우 (위의 예에서는 PI) (이런 경우 final을 이용해서 상수로 선언하는 것이 바람직)
  * 인스턴스를 생성할 필요가 없는 값을 클래스에 저장하고 싶은 경우
  * 값의 변경 사항을 모든 인스턴스가 공유해야 하는 경우


* 클래스 메소드
```
class Calculator3{
  
    public static void sum(int left, int right){
        System.out.println(left+right);
    }
     
    public static void avg(int left, int right){
        System.out.println((left+right)/2);
    }
}
 
public class CalculatorDemo3 {
     
    public static void main(String[] args) {
        Calculator3.sum(10, 20);
        Calculator3.avg(10, 20);
         
        Calculator3.sum(20, 40);
        Calculator3.avg(20, 40);
    }
 
}
```
* 만약 메소드가 인스턴스 변수를 참조하지 않는다면 클래스 메소드를 사용해서 불필요한 인스턴스의 생성을 막을 수 있다.


* 클래스 메소드에 대해서 조금 더 알아보자. 아래 예제는 클래스와 인스턴스의 차이점을 보여주기 위한 예제다. 이 예제는 오류가 포함되어 있기 때문에 실행되지 않을 것이다. 예제의 내용을 살펴보기 전에 몇가지 원칙을 기억해 둔다면 이 예제를 이해하는 것이 조금 수월할 것이다.
  * 인스턴스 메소드는 클래스 맴버에 접근 할 수 있다.
  * 클래스 메소드는 인스턴스 맴버에 접근 할 수 없다.
  * 인스턴스 변수는 인스턴스가 만들어지면서 생성되는데, 클래스 메소드는 인스턴스가 생성되기 전에 만들어지기 때문에 클래스 메소드가 인스턴스 맴버에 접근하는 것은 존재하지 않는 인스턴스 변수에 접근하는 것과 같다.
``` 
class C1{
    static int static_variable = 1;
    int instance_variable = 2;
    // 밑에 static 메소드들
    static void static_static(){
        System.out.println(static_variable);
    	// static 메소드에선 static 변수 접근 가능
    }
    static void static_instance(){
        // 클래스 메소드에서는 인스턴스 변수에 접근 할 수 없다. 
        //System.out.println(instance_variable);
    }
    void instance_static(){
        // 인스턴스 메소드에서는 클래스 변수에 접근 할 수 있다.
        System.out.println(static_variable);
    }
    void instance_instance(){        
        System.out.println(instance_variable);
    }
}
public class ClassMemberDemo {  
    public static void main(String[] args) {
        C1 c = new C1();
        // 인스턴스를 이용해서 정적 메소드에 접근 -> 성공
        // 인스턴스 메소드가 정적 변수에 접근 -> 성공
        c.static_static();
        // 인스턴스를 이용해서 정적 메소드에 접근 -> 성공
        // 정적 메소드가 인스턴스 변수에 접근 -> 실패
        c.static_instance();
        // 인스턴스를 이용해서 인스턴스 메소드에 접근 -> 성공
        // 인스턴스 메소드가 클래스 변수에 접근 -> 성공
        c.instance_static();
        // 인스턴스를 이용해서 인스턴스 메소드에 접근 -> 성공 
        // 인스턴스 메소드가 인스턴스 변수에 접근 -> 성공
        c.instance_instance();
        // 클래스를 이용해서 클래스 메소드에 접근 -> 성공
        // 클래스 메소드가 클래스 변수에 접근 -> 성공
        C1.static_static();
        // 클래스를 이용해서 클래스 메소드에 접근 -> 성공
        // 클래스 메소드가 인스턴스 변수에 접근 -> 실패
        C1.static_instance();
        // 클래스를 이용해서 인스턴스 메소드에 접근 -> 실패
        //C1.instance_static();
        // 클래스를 이용해서 인스턴스 메소드에 접근 -> 실패
        //C1.instance_instance();
    }
 
}
```
* 인스턴스 변수와 클래스 변수는 아래와 같이 부르기도 한다.
  * 인스턴스 변수 -> Non-Static Field
  * 클래스 변수 -> Static Field

* 필드(field)라는 것은 클래스 전역에서 접근 할 수 있는 변수를 의미한다.

* 추가정리
  * 인스턴스 변수는 class 내부에 위차한다, 또한 객체를 생성해야만 사용 할 수 있다.(인스턴스화)
  * 클래스 변수는 인스턴스 변수와 마찬가지로 class 내부에 위치하나 static이 붙어있다. 
  * 인스턴스 변수는 각 인스턴스 마다 독립적인 저장공간을 갖는다. 하지만 클래스 변수는 모든 인스턴스가 같은 저장공간을 공유한다. 그리고 전역 변수 라고 부르기도 한다.

