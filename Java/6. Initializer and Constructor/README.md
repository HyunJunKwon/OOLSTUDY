# Initializer and Constructor

### 초기화
  * 객체 지향 프로그래밍도 초기화에 해당하는 기능이 제공되는데 이것을 생성자(constructor)라고 한다. 
```	
Calculator c1 = new Calculator();
c1.setOprands(10, 20);
c1.sum();       
c1.avg();   
```

* 위의 예에서 메소드 setOprands의 값으로 10과 20을 지정했다. 이 값들은 객체 내부에서 인스턴스 변수 left와 right의 값으로 설정되어서 유지된다. 그런데 이 객체를 이용하기 위해서는 기억해야 할 것이 있다. 아래와 같이 메소드 setOprands를 호출하기 전에 sum과 avg를 호출한다면 원하는 결과를 얻을 수 없을 것이다.

```	
Calculator c1 = new Calculator();
c1.sum();       
c1.avg();
```

* 이것은 객체 Calculator를 사용하기 위해서 사용자는 메소드 sum을 호출하기 전에 setOprands를 호출해야 한다는 것을 기억하고 있어야 한다는 것을 의미한다. 이러한 절차를 기억해야 한다는 것은 사용자 입장에서는 불편할 뿐 아니라 잘못된 사용으로 오류가 발생할 확률을 높이는 결과를 초래 할 수 있다.

<br/>

### 생성자

* 그래서 사용하는 것이 생성자(Constructor)이다. 아래와 같이 인스턴스가 생성될 때 left, right의 값을 입력하도록 강제한다면 어떨까?
```
Calculator c1 = new Calculator(10, 20);
c1.sum();
c1.avg();
```

* 위와 같이 Calculator의 사용방법을 변경하기 위해서는 아래와 같이 코드를 작성한다.

```
class Calculator {
    int left, right;
 
    public Calculator(int left, int right) {
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
 
        Calculator c1 = new Calculator(10, 20);
        c1.sum();
        c1.avg();
 
        Calculator c2 = new Calculator(20, 40);
        c2.sum();
        c2.avg();
    }
 
}
```

* 생성자 덕분에 Calculator 객체를 사용하기 위해서 사실상 반드시 필요한 작업이라고 할 수 있는 좌항(left)과 우항(right)의 값을 설정하는 과정을 객체 생성 과정에서 강제할 수 있게 되었다. 절차를 하나 줄인 것뿐이지만, 객체를 사용하기 위해서는 객체를 생성해야 한다는 사실은 기본적으로 숙지하고 있는 절차이기 때문에 이 절차에 필수적인 작업을 포함시킨다는 것은 중요한 의미를 갖게 된다.

* 생성자의 특징
  * 생성자의 특징은 아래와 같이 정리할 수 있다.
    * 값을 반환하지 않는다. 
    * 생성자는 인스턴스를 생성해주는 역할을 하는 특수한 메소드라고 할 수 있다. 그런데 반환 값이 있다면 엉뚱한 객체가 생성될 것이다. 따라서 반환 값을 필요로하는 작업에서는 생성자를 사용하지 않는다. 반환 값이 없기 때문에 return도 사용하지 않고, 반환 값을 메소드 정의에 포함시키지도 않는다. 
    * 생성자의 이름은 클래스의 이름과 동일하다. 
    * 자바에서 클래스의 이름과 동일한 메소드는 생성자로 사용하기로 약속되어 있다.
