# Access Modifier


### 접근 제어자

* 접근 제어자는 클래스의 맴버(변수와 메소드)들의 접근 권한을 지정한다.

```
package org.opentutorials.javatutorials.accessmodifier;
class A {
    public String y(){
        return "public void y()";
    }
    private String z(){
        return "public void z()";
    }
    public String x(){
        return z();
    }
}
public class AccessDemo1 {
    public static void main(String[] args) {
        A a = new A();
        System.out.println(a.y());
        // 아래 코드는 오류가 발생한다.
        //System.out.println(a.z());
        System.out.println(a.x());
    }
}
```

* 이 코드는 실행된다. ```System.out.println(a.y());``` 하지만 이 코드는 오류를 발생시킨다. ```System.out.println(a.z());``` 오류의 내용은 아래와 같다.

```	
Exception in thread "main" java.lang.Error: Unresolved compilation problem: 
    The method z() from the type A is not visible
    at org.opentutorials.javatutorials.accessmodifier.AccessDemo1.main(AccessDemo1.java:15)
```

* 즉 메소드 z에 접근 할 수 없다는 의미다. 메소드 z의 본체를 보자.

```	
private String z(){
    return "public void z()";
}
```

* 메소드가 키워드 private으로 시작되고 있다. private은 클래스(A) 밖에서는 접근 할 수 없다는 의미다. 바로 이 private의 자리에 오는 것들을 접근 제어자(access modifier)라고 한다. 그럼 사용할 수 없는 메소드를 왜 정의하고 있는 것일까? 내부적으로 사용하기 위해서다.

* ```System.out.println(a.x());``` 메소드 x의 본체는 아래와 같다.

```
public String x(){
    return z();
}
```

* 접근 제어자가 public이기 때문에 호출 할 수 있다. 그리고 메소드의 내용을 보면 내부적으로 메소드 z를 호출하고 있다. 메소드 z는 정상적으로 호출된다. 왜냐하면 메소드 x와 메소드 z는 같은 클래스의 소속이기 때문이다. 따라서 메소드 x에서 z를 호출 할 수 있는 것이다.


### 접근 제어자를 사용하는 이유

* 객체의 로직을 보호하기 위해서는 맴버에 따라서 외부의 접근을 허용하거나 차단해야 할 필요가 생긴다. 접근 제어자를 사용하는 또 다른 이유는 사용자에게 객체를 조작 할 수 있는 수단만을 제공함으로서 결과적으로 객체의 사용에 집중 할 수 있도록 돕기 위함이다.

### 세밀한 제어

* 접근 제어자는 public과 private외에도 두가지가 더 있다. protected과 default가 그것이다. protected는 상속 관계에 있다면 서로 다른 패키지에 있는 클래스의 접근도 허용한다. default는 접근 제어 지시자가 없는 경우를 의미하는데, 접근 제어자가 없는 메소드는 같은 패키지에 있고 상속 관계에 있는 메소드에 대해서만 접근을 허용한다. 아래 그림은 접근 제어자 별로 접근의 허용범위를 그림으로 나타낸 것이다. 안쪽에 있을수록 접근 통제가 삼엄하고, 밖에 있을수록 접근이 허용된다.
 
* 그림
  *                             public ⊃ protected ⊃ default ⊃ private
  * 같은 패키지, 같은 클래스 	    허용 	   허용 		    허용 		  허용
  * 같은 패키지, 상속 관계 	     허용     허용 	       허용 		  불용
  * 같은 패키지, 상속 관계 아님    허용 	   허용 		   허용 		  불용
  * 다른 패키지, 상속 관계 	     허용 	  허용 		     불용 		  불용
  * 다른 패키지, 상속 관계 아님 	  허용 	   불용 		   불용 		  불용

* 위의 관계는 필드(변수)에도 적용. 또한 클래스 맴버(static)에게도 적용.


### 클래스의 접근 제어자

* 지금까지는 클래스 맴버에 대한 접근 제어자를 살펴봤다. 이번에 살펴볼 것은 클래스의 접근 제어자다. 클래스도 접근 제어자가 있다. 클래스의 접근 제어자는 총 2개로 public과 default이다. default는 접근 제어자를 붙이지 않은 경우 default가 된다. 클래스의 접근 제어자는 패키지와 관련된 개념이다. 즉 접근 제어자가 public인 클래스는 다른 패키지의 클래스에서도 사용할 수 있고, default인 경우는 같은 패키지에서만 사용 가능하다.

```
package org.opentutorials.javatutorials.accessmodifier.inner;
public class PublicClass {}
```

```	
package org.opentutorials.javatutorials.accessmodifier.inner;
class DefaultClass {}
```

* 위의 클래스들과 같은 패키지에서 이 클래스들을 사용해보자. 문제 없다.

```
package org.opentutorials.javatutorials.accessmodifier.inner;
public class ClassAccessModifierInnerPackage {
    PublicClass publicClass = new PublicClass();
    DefaultClass defaultClass = new DefaultClass();
}
```

* 이번에는 다른 패키지에 있는 클래스에서 사용해보자.

```
package org.opentutorials.javatutorials.accessmodifier.outter;
import org.opentutorials.javatutorials.accessmodifier.inner.*;
public class ClassAccessModifierOuterPackage {
    PublicClass publicClass = new PublicClass();
    //DefaultClass defaultClass = new DefaultClass();
}
```
* 주석으로 처리한 부분은 오류가 발생한다. DefaultClass의 접근 제어자가 default이기 때문이다.

* 한가지 중요한 제약 사항이 있다. public 클래스가 포함된 소소코드는 public 클래스의 클래스 명과 소스코드의 파일명이 같아야 한다. 코드를 보자. 이 코드의 이름은 PublicNameDemo.java이다.

```
package org.opentutorials.javatutorials.accessmodifier.inner;
//public class PublicName {}
public class PublicNameDemo {}
```

* 주석처리된 부분은 오류가 발생한다. 퍼블릭 클래스의 이름과 소스코드의 이름이 일치하지 않기 때문이다. 그 말은 하나의 소스 코드에는 하나의 public 클래스가 존재 할 수 있다는 의미다.
