# Overriding

* 창의적인 상속
  * 하위 클래스가 부모 클래스의 기본적인 동작방법을 변경할 수 있어야 한다. 이런 맥락에서 도입된 기능이 메소드 오버라이딩(overriding)이다.

```
상속 토픽의 예제를 조금 변경해보자.
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
 
class SubstractionableCalculator extends Calculator {
     
    public void sum() {
        System.out.println("실행 결과는 " +(this.left + this.right)+"입니다.");
    }
     
    public void substract() {
        System.out.println(this.left - this.right);
    }
}
 
public class CalculatorDemo {
    public static void main(String[] args) {
        SubstractionableCalculator c1 = new SubstractionableCalculator();
        c1.setOprands(10, 20);
        c1.sum();
        c1.avg();
        c1.substract();
    }
}
/*
15
-10
*/
```

* 메소드 sum이  SubstractionableCalculator에 추가 되었다. 실행결과는 c1.sum이 상위 클래스의 메소드가 아니라 하위 클래스의 메소드 sum을 실행하고 있다는 것을 보여준다. 하위 클래스 입장에서 부모 클래스란 말하자면 기본적인 동작 방법을 정의한 것이라고 생각할 수 있다. 하위 클래스에서 상의 클래스와 동일한 메소드를 정의하면 부모 클래스로부터 물려 받은 기본 동작 방법을 변경하는 효과를 갖게 된다. 기본동작은 폭넓게 적용되고, 예외적인 동작은 더 높은 우선순위를 갖게하고 있다. 이것은 공학에서 일반적으로 발견되는 규칙이다. 이것을 메소드 오버라이딩(overriding)이라고 한다.


### 오버라이딩의 조건

```
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
 
class SubstractionableCalculator extends Calculator {
     
    public void sum() {
        System.out.println("실행 결과는 " +(this.left + this.right)+"입니다.");
    }
     
    public int avg() {
        return (this.left + this.right)/2;
    }
     
    public void substract() {
        System.out.println(this.left - this.right);
    }
}
 
public class CalculatorDemo {
    public static void main(String[] args) {
        SubstractionableCalculator c1 = new SubstractionableCalculator();
        c1.setOprands(10, 20);
        c1.sum();
        c1.avg();
        c1.substract();
    }
}

/*
이것은 아래와 같은 에러를 발생한다.	
Exception in thread "main" java.lang.Error: Unresolved compilation problem: 
    The return type is incompatible with Calculator.avg()
    at org.opentutorials.javatutorials.overriding.example1.SubstractionableCalculator.avg(CalculatorDemo.java:26)
    at org.opentutorials.javatutorials.overriding.example1.CalculatorDemo.main(CalculatorDemo.java:40)
/*
```

* overriding을 하기 위해서는 메소드의 리턴 형식이 같아야 한다. 즉 클래스 Calculator의 메소드 avg는 리턴 타입이 void이다. 그런데 이것을 상속한 클래스 SubstractionableCalculator의 리턴 타입은 int이다. 오버라이딩을 하기 위해서는 아래의 조건을 충족시켜야 한다.
  * 메소드의 이름
  * 메소드 매개변수의 숫자와 데이터 타입 그리고 순서 
  * 메소드의 리턴 타입

* 위와 같이 메소드의 형태를 정의하는 사항들을 통털어서 메소드의 서명(signature)라고 한다. 즉 위의 에러는 메소드들 간의 서명이 달라서 발생한 문제다. 아래와 같이 상위 클래스의 코드를 변경해서 이 문제를 우회하자.
```
class Calculator {
    int left, right;
 
    public void setOprands(int left, int right) {
        this.left = left;
        this.right = right;
    }
 
    public void sum() {
        System.out.println(this.left + this.right);
    }
 
    public int avg() {
        return ((this.left + this.right) / 2);
    }
}
 
class SubstractionableCalculator extends Calculator {
     
    public void sum() {
        System.out.println("실행 결과는 " +(this.left + this.right)+"입니다.");
    }
     
    public int avg() {
        return ((this.left + this.right) / 2);
    }
     
    public void substract() {
        System.out.println(this.left - this.right);
    }
}
 
public class CalculatorDemo {
    public static void main(String[] args) {
        SubstractionableCalculator c1 = new SubstractionableCalculator();
        c1.setOprands(10, 20);
        c1.sum();
        c1.avg();
        c1.substract();
    }
}
```

* 상위 클래스와 하위 클래스의 서명이 같기 때문에 메소드 오버라이딩을 할 수 있었다. 그런데 위의 코드를 보면 중복이 발생했다. 메소드 avg의 부모와 자식 클래스가 같은 로직을 가지고 있다. 중복은 제거 되어야 한다. 생성자와 마찬가지로 super를 사용하면 이 문제를 해결 할 수 있다.

```
class Calculator {
    int left, right;
 
    public void setOprands(int left, int right) {
        this.left = left;
        this.right = right;
    }
 
    public void sum() {
        System.out.println(this.left + this.right);
    }
 
    public int avg() {
        return ((this.left + this.right) / 2);
    }
}
 
class SubstractionableCalculator extends Calculator {
     
    public void sum() {
        System.out.println("실행 결과는 " +(this.left + this.right)+"입니다.");
    }
     
    public int avg() {
        return super.avg();
    }
     
    public void substract() {
        System.out.println(this.left - this.right);
    }
}
 
public class CalculatorDemo {
    public static void main(String[] args) {
        SubstractionableCalculator c1 = new SubstractionableCalculator();
        c1.setOprands(10, 20);
        c1.sum();
        System.out.println("실행 결과는" + c1.avg());
        c1.substract();
    }
}
```

* 하위 클래스의 메소드 avg에서 상위 클래스의 메소드를 호출하기 위해서 super를 사용하고 있다. 덕분에 코드의 중복을 제거 할 수 있었다.


# Overloading

* 계산기 예제로 돌아가보자. 우리의 계산기는 2개의 값(left, right)에 대한 연산(sum, avg) 만을 수행 할 수 있다. 그런데 만약 3개의 값을 대상으로 연산을 해야 한다면 어떻게 해야할까? 우선 입력값을 3개 받아야 할 것이다. ```c1.setOprands(10, 20, 30);``` 이를 위해서 기존의 setOprands 메소드를 아래와 같은 모습을 수정한다면 2개의 입력값을 받을 수 없게 될 것이다.

```	
public void setOprands(int left, int right, int third){
    this.left = left;
    this.right = right;
    this.third = third;
}
```

* 이런 경우 아래와 같이 메소드의 이름을 변경하면 될 것이다.

```	
c1.setOprands2(10, 20);
c1.setOprands3(10, 20, 30);
```

* 이것도 좋은 방법이지만 매개변수의 수에 따라서 메소드의 이름이 달라지는 것은 왠지 깔끔한 방법이 아니다.

```
class Calculator{
    int left, right;
    int third = 0;
      
    public void setOprands(int left, int right){
        System.out.println("setOprands(int left, int right)");
        this.left = left;
        this.right = right;
    }
     
    public void setOprands(int left, int right, int third){
        System.out.println("setOprands(int left, int right, int third)");
        this.left = left;
        this.right = right;
        this.third = third;
    }
     
    public void sum(){
        System.out.println(this.left+this.right+this.third);
    }
      
    public void avg(){
        System.out.println((this.left+this.right+this.third)/3);
    }
}
  
public class CalculatorDemo {
      
    public static void main(String[] args) {
          
        Calculator c1 = new Calculator();
        c1.setOprands(10, 20);
        c1.sum();       
        c1.avg();
        c1.setOprands(10, 20, 30);
        c1.sum();       
        c1.avg();
         
    }
  
}
/*	
setOprands(int left, int right)
30
15
setOprands(int left, int right, int third)
60
30
*/
```

* 이름은 같지만 시그니처는 다른 메소드를 중복으로 선언 할 수 있는 방법을 메소드 오버로딩(overloading)이라고 한다.

### 오버로딩의 규칙

* 결론적으로 말하면 메소드 오버로딩은 매개변수를 사용한다. 즉 매개변수가 다르면 이름이 같아도 서로 다른 메소드가 되는 것이다. 반면에 매개변수는 같지만 리턴타입이 다르면 오류가 발생한다. 
```
public class OverloadingDemo {
    void A (){System.out.println("void A()");}
    void A (int arg1){System.out.println("void A (int arg1)");}
    void A (String arg1){System.out.println("void A (String arg1)");}
    //int A (){System.out.println("void A()");}
    public static void main(String[] args) {
        OverloadingDemo od = new OverloadingDemo();
        od.A();
        od.A(1);
        od.A("coding everybody");
    }
}
```
* 메소드의 반환값은 메소드를 호출하는 시점에서 전달되지 않는 정보이기 때문에 오버로딩의 대상이 될 수 없다.

### 상속과 오버로딩

```
public class OverloadingDemo2 extends OverloadingDemo{
    void A (String arg1, String arg2){System.out.println("sub class : void A (String arg1, String arg2)");}
    void A (){System.out.println("sub class : void A ()");}
    public static void main(String[] args) {
        OverloadingDemo2 od = new OverloadingDemo2();
        od.A();
        od.A(1);
        od.A("coding everybody");
        od.A("coding everybody", "coding everybody");
         
    }
}

/*
sub class : void A ()
void A (int arg1)
void A (String arg1)
sub class : void A (String arg1, String arg2)
*/
```
클래스 OverloadingDemo2는 OverloadingDemo을 상속 받고 있다. OverloadingDemo2의 3행에서 정의된 메소드 A는 문자열을 데이터타입으로 하는 두개의 매개변수를 가지고 있다. 이러한 형태의 변수는 부모 클래스에서는 정의되어 있지 않기 때문에 메소드 오버로딩이 되는 것이다. 반면에 4행에서 정의된 메소드 A는 매개변수가 없다. 그리고 부모 클래스에는 이미 매개변수가 없는 메소드 A가 존재한다. 이 둘은 매개변수의 형태가 같기 때문에 오버로딩이 아니라 오버라이딩에 해당한다.
