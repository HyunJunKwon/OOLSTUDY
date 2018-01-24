# Exception

* 에러 메시지는 시스템에서 어떤 오류가 발생했을 때 그 오류를 이해하고 파악하는데 큰 도움이 된다.

* ```try...catch```는 예외에서 핵심적인 역할을 담당하는 문법적인 요소다. 형식을 살펴보자.

### try

* try 안에는 예외 상황이 발생할 것으로 예상되는 로직을 위치시킨다. 

### catch

* catch 안에는 예외가 발생했을 때 뒷수습을 하기 위한 로직이 위치한다. 구문에서 오류가 발생하면서 try 내의 실행이 중단되고 catch 구문 안의 내용이 실행된다.

### 예외 클래스와 인스턴스

```	
} catch(Exception e){
    System.out.println("오류가 발생했습니다 : "+e.getMessage());
}
```

* e는 변수다. 이 변수 앞의 Exception은 변수의 데이터 타입이 Exception이라는 의미다. Exception은 자바에서 기본적으로 제공하는 클래스로 java.lang에 소속되어 있다. 예외가 발생하면 자바는 마치 메소드를 호출하듯이 catch를 호출하면서 그 인자로 Exception 클래스의 인스턴스를 전달하는 것이다.
* e.getMessage()는 자바가 전달한 인스턴스의 메소드 중 getMessage를 호출하는 코드인데, getMessage는 오류의 원인을 사람이 이해하기 쉬운 형태로 리턴하도록 약속되어 있다.

### 뒷수습의 방법

```	
package org.opentutorials.javatutorials.exception;
class Calculator{
    int left, right;
    public void setOprands(int left, int right){
        this.left = left;
        this.right = right;
    }
    public void divide(){
        try {
            System.out.print("계산결과는 ");
            System.out.print(this.left/this.right);
            System.out.print(" 입니다.");
        } catch(Exception e){
            System.out.println("\n\ne.getMessage()\n"+e.getMessage());
            System.out.println("\n\ne.toString()\n"+e.toString());
            System.out.println("\n\ne.printStackTrace()");
            e.printStackTrace();
        }
    }
} 
public class CalculatorDemo {
    public static void main(String[] args) {
        Calculator c1 = new Calculator();
        c1.setOprands(10, 0);
        c1.divide();
    }
}
```	

* 계산결과는 

``` 
e.getMessage()
/ by zero
 
 
e.toString()
java.lang.ArithmeticException: / by zero
 
 
e.printStackTrace()
java.lang.ArithmeticException: / by zero
    at org.opentutorials.javatutorials.exception.Calculator.divide(CalculatorDemo.java:11)
    at org.opentutorials.javatutorials.exception.CalculatorDemo.main(CalculatorDemo.java:25)
```

* e.getMessage();
오류에 대한 기본적인 내용을 출력해준다. 상세하지 않다.

* e.toString()
e.toString()을 호출한 결과는 java.lang.ArithmeticException: / by zero 이다. e.toString()은 e.getMessage()보다 더 자세한 예외 정보를 제공한다. java.lang.ArithmeticException은 발생한 예외가 어떤 예외에 해당하는지에 대한 정보라고 지금을 생각하자. ArithmeticException 수학적인 계산의 과정에서 발생하는 예외상황을 의미한다. (우리는 어떤 숫자를 0으로 나누려고 하고 있다는 것을 상기하자)

* e.printStackTrace()
메소드 getMessage, toString과는 다르게 printStackTrace는 리턴값이 없다. 이 메소드를 호출하면 메소드가 내부적으로 예외 결과를 화면에 출력한다. printStackTrace는 가장 자세한 예외 정보를 제공한다.


### 다양한 예외들

```
package org.opentutorials.javatutorials.exception;
 
class A{
    private int[] arr = new int[3];
    A(){
        arr[0]=0;
        arr[1]=10;
        arr[2]=20;
    }
    public void z(int first, int second){
        System.out.println(arr[first] / arr[second]);
    }
}
 
public class ExceptionDemo1 {
    public static void main(String[] args) {
        A a = new A();
        a.z(10, 1);
    }
}
```

* 위의 결과는 아래와 같다.

```
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 10
    at org.opentutorials.javatutorials.exception.A.z(ExceptionDemo1.java:11)
    at org.opentutorials.javatutorials.exception.ExceptionDemo1.main(ExceptionDemo1.java:18)
```

* 이유를 따져보자. 배열 arr은 3개의 값을 담을 수 있다. 하지만 10번째 인덱스를 호출하고 있다. ```a.z(10, 1);``` 따라서 존재하지 않는 값을 가져오려고 시도하고 있기 때문에 자바에서는 ArrayIndexOutOfBoundsException을 발생시킨 것이다.

* 코드를 조금 변형시켜보면,

```
package org.opentutorials.javatutorials.exception;
 
class A{
    private int[] arr = new int[3];
    A(){
        arr[0]=0;
        arr[1]=10;
        arr[2]=20;
    }
    public void z(int first, int second){
        System.out.println(arr[first] / arr[second]);
    }
}
 
public class ExceptionDemo1 {
    public static void main(String[] args) {
        A a = new A();
        a.z(1, 0);
    }
}
```

* 결과는 아래와 같다.

```
Exception in thread "main" java.lang.ArithmeticException: / by zero
    at org.opentutorials.javatutorials.exception.A.z(ExceptionDemo1.java:11)
    at org.opentutorials.javatutorials.exception.ExceptionDemo1.main(ExceptionDemo1.java:18)
```

* 위의 코드는 메소드 z 내부적으로 10/0을 실행하게 된다. 0으로 나누는 것은 불가능하기 때문에 자바는 ArithmeticException을 발생시킨다.

* 위의 예제를 통해서 보여주고 싶은 것은 같은 로직이지만 상황에 따라서 다른 예외가 발생할 수 있다는 것이다. 이런 경우는 어떻게 예외를 처리해야 할까? 예외 처리를 추가한 아래의 예제를 보자.

```
package org.opentutorials.javatutorials.exception;
 
class A{
    private int[] arr = new int[3];
    A(){
        arr[0]=0;
        arr[1]=10;
        arr[2]=20;
    }
    public void z(int first, int second){
        try {
            System.out.println(arr[first] / arr[second]);
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ArrayIndexOutOfBoundsException");
        } catch(ArithmeticException e){
            System.out.println("ArithmeticException");
        } catch(Exception e){
            System.out.println("Exception");
        }
         
    }
}
 
public class ExceptionDemo1 {
    public static void main(String[] args) {
        A a = new A();
        a.z(10, 0);
        a.z(1, 0);
        a.z(2, 1);
    }
}
```

* 결과는 다음과 같다.

```
ArrayIndexOutOfBoundsException
ArithmeticException
2
```

* 예제는 다중 catch를 보여준다. 조건문의 else if처럼 여러 개의 catch를 하나의 try 구문에서 사용할 수 있다. 이를 통해서 보다 간편하게 다양한 상황에 대응할 수 있다. 위의 코드는 try 구문에서 예외가 발생했을 때 그 예외의 종류가 ArrayIndexOutOfBoundsException이라면 14행이 실행되고, ArithemeticException이라면 16행이 실행되고 그 외의 것이라면 18행이 실행된다는 의미다.

* 만약 아래와 같이 메소드 z의 코드를 변경한다면 어떻게 될까? 아래와 같은 메시지가 출력되면서 컴파일 조차 되지 않을 것이다.

```	
Exception in thread "main" java.lang.Error: Unresolved compilation problems: 
    Unreachable catch block for ArrayIndexOutOfBoundsException. It is already handled by the catch block for Exception
    Unreachable catch block for ArithmeticException. It is already handled by the catch block for Exception
 
    at org.opentutorials.javatutorials.exception.A.z(ExceptionDemo1.java:15)
    at org.opentutorials.javatutorials.exception.ExceptionDemo1.main(ExceptionDemo1.java:27)
```

* 그것은 Exception이 ArrayIndexOutOfBoundsException, ArithemeticException 보다 포괄적인 예외를 의미하기 때문에 Exception 이후에 등장하는 catch 문은 실행될 수 없는 구문이기 때문이다. 자바 컴파일러가 불필요한 로직을 감지하고 이를 개발자에게 알려주는 것이다.

### finally

* finally는 try 구문에서 예외가 발생하는 것과 상관없이 언제나 실행되는 로직이다. 예제를 조금 변경해보자.

```	
package org.opentutorials.javatutorials.exception;
 
class A{
    private int[] arr = new int[3];
    A(){
        arr[0]=0;
        arr[1]=10;
        arr[2]=20;
    }
    public void z(int first, int second){
        try {
            System.out.println(arr[first] / arr[second]);
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ArrayIndexOutOfBoundsException");
        } catch(ArithmeticException e){
            System.out.println("ArithmeticException");
        } catch(Exception e){
            System.out.println("Exception");
        } finally {
            System.out.println("finally");
        }
    }
}
 
public class ExceptionDemo1 {
    public static void main(String[] args) {
        A a = new A();
        a.z(10, 0);
        a.z(1, 0);
        a.z(2, 1);
    }
}
```

* 실행결과는 다음과 같다.

```	
ArrayIndexOutOfBoundsException
finally
ArithmeticException
finally
2
finally
```

* 예외와 상관없이 try 내의 구문이 실행되면 finally가 실행되고 있다.

* 그럼 finally는 언제 사용하는 것일까? 어떤 작업의 경우는 예외와는 상관없이 반드시 끝내줘야 하는 작업이 있을 수 있다. 말하자면 finally는 작업의 뒷정리를 담당한다고 볼 수 있다.

<br/>

# 예외 던지기

### 예외의 강제

* API를 사용할 때 설계자의 의도에 따라서 예외를 반드시 처리해야 하는 경우가 있다. 아래의 예제를 보자.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
public class CheckedExceptionDemo {
    public static void main(String[] args) {
        BufferedReader bReader = new BufferedReader(new FileReader("out.txt"));
        String input = bReader.readLine();
        System.out.println(input); 
    }
}
```
* out.txt 파일을 읽어서 그것을 화면에 출력하는 내용이다. 이 코드를 실행시키려면 out.txt 파일을 프로젝트의 루트 디렉토리에 위치시켜야 한다. 이클립스 기반으로 필자의 화면을 공유하면 아래와 같은 위치에 이 파일이 있어야 한다. 위의 코드를 컴파일해보면 아래와 같은 에러가 발생하면서 컴파일이 되지 않을 것이다.

```	
Exception in thread "main" java.lang.Error: Unresolved compilation problems: 
    Unhandled exception type FileNotFoundException
    Unhandled exception type IOException
 
    at org.opentutorials.javatutorials.exception.CheckedExceptionDemo.main(CheckedExceptionDemo.java:5)
```

* Unhandled exception type FileNotFoundException : 이것은 아래 로직에 대한 예외처리가 필요하다는 뜻이다. 

* ```new FileReader("out.txt")```

* FileReader라는 클래스를 API문서에서 찾아보자. FileReader의 생성자를 문서에서 찾아보면 아래와 같은 부분이 있다.

* Throws는 한국어로는 '던지다'로 번역된다. 위의 내용은 생성자 FileReader의 인자 fileName의 값에 해당하는 파일이 디렉토리이거나 어떤 이유로 사용할 수 없다면 FileNotFoundException을 발생시킨다는 의미다. 이것은 FileReader의 생성자가 동작할 때 파일을 열 수 없는 경우가 생길 수 있고, 이런 경우 생성자 FileReader에서는 이 문제를 처리할 수 없기 때문에 이에 대한 처리를 생성자의 사용자에게 위임하겠다는 의미다. 그것을 던진다(throw)고 표현하고 있다. 따라서 API의 사용자 쪽에서는 예외에 대한 처리를 반드시 해야 한다는 의미다. 따라서 아래와 같이 해야 FileReader 클래스를 사용할 수 있다.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
public class CheckedExceptionDemo {
    public static void main(String[] args) {
        try {
            BufferedReader bReader = new BufferedReader(new FileReader("out.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String input = bReader.readLine();
        System.out.println(input); 
    }
}
```

* BufferedReader 클래스의 readLine 메소드는 IOException을 발생시킬 수 있다. 아래와 같이 코드를 수정하자.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
public class CheckedExceptionDemo {
    public static void main(String[] args) {
        try {
            BufferedReader bReader = new BufferedReader(new FileReader("out.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try{
            String input = bReader.readLine();
        } catch (IOException e){
            e.printStackTrace();
        }       
        System.out.println(input); 
    }
}
```

* 그런데 위의 코드는 컴파일되지 않는다. 여기에는 함정이 있는데 변수 bReader를 보자. 이 변수는 try의 중괄호 안에서 선언되어 있다. 그리고 이 변수는 11행에서 사용되는데 bReader가 선언된 6행과 사용될 11행은 서로 다른 중괄호이다. 따라서 11행에서는 6행에서 선언된 bReader에 접근할 수 없다. 

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
public class CheckedExceptionDemo {
    public static void main(String[] args) {
        BufferedReader bReader = null;
        String input = null;
        try {
            bReader = new BufferedReader(new FileReader("out.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try{
            input = bReader.readLine();
        } catch (IOException e){
            e.printStackTrace();
        }       
        System.out.println(input); 
    }
}
```

### throw와 throws

* 지금까지 예외를 처리하는 방법으로 try...catch...finally를 배웠다. 이외에 다른 방법도 있다.  throw를 사용하는 것이다. throw는 예외처리를 다음 사용자에게 넘기는 것이다.

```	
package org.opentutorials.javatutorials.exception;
 
class B{
    void run(){
    }
}
class C{
    void run(){
        B b = new B();
        b.run();
    }
}
public class ThrowExceptionDemo {
    public static void main(String[] args) {
         C c = new C();
         c.run();
    }   
}
```

* ThrowExceptionDemo.main(클래스 ThrowExceptionDem의 메소드 main)은 C.run의 사용자이다. C.run은 B.run의 사용자이다. 반대로 B.run의 다음 사용자는 C.run이고 C.run의 다음 사용자는 ThrowExceptionDem.main이 되는 셈이다. 파일을 읽은 로직을 추가해보자.

```
package org.opentutorials.javatutorials.exception;
import java.io.*;
class B{
    void run(){
        BufferedReader bReader = null;
        String input = null;
        try {
            bReader = new BufferedReader(new FileReader("out.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try{
            input = bReader.readLine();
        } catch (IOException e){
            e.printStackTrace();
        }       
        System.out.println(input); 
    }
}
class C{
    void run(){
        B b = new B();
        b.run();
    }
}
public class ThrowExceptionDemo {
    public static void main(String[] args) {
         C c = new C();
         c.run();
    }   
}
```

* 위의 코드는 B.run이 FileReader의 생성자와 BufferedReader.readLine가 던진 예외를 try...catch로 처리한다. 즉 B.run이 예외에 대한 책임을 지고 있다. 그런데 B.run이 예외 처리를 직접 하지 않고 다음 사용자 C.run에게 넘길 수 있다. 아래의 코드를 보자.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
class B{
    void run() throws IOException, FileNotFoundException{
        BufferedReader bReader = null;
        String input = null;
        bReader = new BufferedReader(new FileReader("out.txt"));
        input = bReader.readLine();
        System.out.println(input); 
    }
}
class C{
    void run(){
        B b = new B();
        b.run();
    }
}
public class ThrowExceptionDemo {
    public static void main(String[] args) {
         C c = new C();
         c.run();
    }   
}
```

* B 내부의 try...catch 구문은 제거되었고 run 옆에 throws IOException, FileNotFoundException이 추가되었다. 이것은 B.run 내부에서 IOException, FileNotFoundException에 해당하는 예외가 발생하면 이에 대한 처리를 B.run의 사용자에게 위임하는 것이다. 위의 코드에서 B.run의 사용자는 C.run이다. 따라서 C.run은 아래와 같이 수정돼야 한다.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
class B{
    void run() throws IOException, FileNotFoundException{
        BufferedReader bReader = null;
        String input = null;
        bReader = new BufferedReader(new FileReader("out.txt"));
        input = bReader.readLine();
        System.out.println(input);
    }
}
class C{
    void run(){
        B b = new B();
        try {
            b.run();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
public class ThrowExceptionDemo {
    public static void main(String[] args) {
         C c = new C();
         c.run();
    }   
}
```
* 이 책임을 다시 main에게 넘겨보자.

```	
package org.opentutorials.javatutorials.exception;
import java.io.*;
class B{
    void run() throws IOException, FileNotFoundException{
        BufferedReader bReader = null;
        String input = null;
        bReader = new BufferedReader(new FileReader("out.txt"));
        input = bReader.readLine();
        System.out.println(input);
    }
}
class C{
    void run() throws IOException, FileNotFoundException{
        B b = new B();
        b.run();
    }
}
public class ThrowExceptionDemo {
    public static void main(String[] args) {
         C c = new C();
         try {
            c.run();
        } catch (FileNotFoundException e) {
            System.out.println("out.txt 파일은 설정 파일 입니다. 이 파일이 프로잭트 루트 디렉토리에 존재해야 합니다.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }   
}
```

* out.txt 파일을 찾을 수 없는 상황은 B.run 입장에서는 어떻게 할 수 있는 일이 아니다. 엔드유저인 애플리케이션의 사용자가 out.txt 파일을 루트 디렉토리에 위치시켜야 하는 문제이기 때문에 애플리케이션의 진입점인 메소드 main으로 책임을 넘기고 있다. 
* 예외 처리는 귀찮은 일이다. 그래서 예외를 다음 사용자에게 전가(throw)하거나 try...catch로 감싸고 아무것도 하지 않고 싶은 유혹에 빠지기 쉽다. 하지만 예외는 API를 사용하면서 발생할 수 있는 잠재적 위협에 대한 API 개발자의 강력한 암시다. 이 암시를 무시해서는 안 된다. 물론 더욱 고민스러운 것은 예외 처리 방법에 정답이 없다는 것이겠지만 말이다.

<br/>

# 예외의 종류

* Throwable, Error, Exception, Runtime Exception

 
### Throwable

* 클래스 Throwable은 범 예외 클래스들의 공통된 조상이다. 모든 예외 클래스들이 가지고 있는 공통된 메소드를 정의하고 있다. 중요한 역할을 하는 클래스임에는 틀림없지만 이 클래스를 직접 사용하지는 않기 때문에 우리에게는 중요하지 않다.

### Error

* 에러는 여러분의 애플리케이션의 문제가 아니라 그 애플리케이션이 동작하는 가상머신에 문제가 생겼을 때 발생하는 예외다. 애플리케이션을 구동시키기에는 메모리가 부족한 경우가 이에 속한다. 이런 경우는 애플리케이션 개발자가 할 수 있는 것이 없다. 따라서 예외처리를 하지 말고 그냥 에러로 인해서 애플리케이션이 중단되도록 내버려둔다. 대신 자신의 애플리케이션이 메모리를 과도하게 사용하고 있다면 로직을 변경하거나 자바 가상머신에서 사용하는 메모리의 제한을 변경하는 등의 대응을 한다.

###Exception

* 결국 우리의 관심사는 Exception 클래스와 RuntimeException 클래스로 좁혀진다. 우선 Exception 클래스의 하위 클래스들의 목록을 살펴보자. 아래 클래스들은 모두 Exception 클래스를 상속한 예외 클래스다.
  * checked 예외 - RuntimeException을 제외한 Exception의 하위 클래스
  * unchekced 예외 - RuntimeException의 하위 클래스
