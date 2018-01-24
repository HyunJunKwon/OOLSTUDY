# Package

### package

* 클래스 패스란 컴퓨터의 저장장치 어딘가에 존재하는 클래스 파일을 사용하기 위한 방법이다. 패키지(Package)는 하나의 클래스 안에서 같은 이름의 클래스들을 사용하기 위한 방법이라고 할 수 있다.
비유를 해보자. 서로 다른 내용의 파일 java.txt가 하나의 컴퓨터에 동시에 공존할 수는 없다. 그래서 고안된 것이 디렉토리다. java.txt 파일을 각각 a와 b라는 디렉터리에 저장한다면 하나의 컴퓨터 안에 같은 이름의 파일이 공존할 수 있게 된다. 누군가에게 'a 디렉터리에 있는 java.txt'를 이메일로 보내달라고 요청할 수 있게 되는 것이다.
패키지도 이와 유사하다. 클래스가 많아짐에 따라서 같은 이름을 가진 클래스가 생겨날 가능성이 높아지게 되는데 이름의 충돌을 방지하기 위한 고안된 것이 패키지라고 할 수 있다.
정보 공학에서는 '이름의 충돌'이라는 문제를 해결하기 위해서 다양한 노력을 하고 있다. 전역변수와 지역변수, 객체도 그런 연장선에 있다고 볼 수 있다.

### 패키지 만들기

* 우리는 이미 패키지를 사용해왔다. 일부 IDE들은 패키지의 사용을 강제하고 있기 때문에 독자가 패키지가 무엇인지도 숙지하지 않은 상태에서 패키지를 사용한 것이다. 이미 사용해본 패키지들을 살펴보자. 토픽 "클래스와 인스턴스 그리고 객체"의 예제에는 아래와 같은 구문이 있다. ```package org.opentutorials.javatutorials.object;``` 또 토픽 "클래스 맴버와 인스턴스 맴버"의 예제에는 아래와 같은 구문이 있다. ```package org.opentutorials.javatutorials.classninstance;``` 
그럼 각 클래스들의 위치를 찾아보자. 이클립스에서는 파일을 선택하고 오른쪽 클릭을 하면 메뉴 하단에 properties 항목을 선택하면 Location이 소스코드가 위치하는 경로다. 
아래 코드를 보자. 아래 코드의 파일명은 A.java이다. 패키지명은 일반적으로 클래스를 제작한 개인이나 단체가 소속된 웹사이트의 도메인을 이용한다. 패키지의 이름도 중복될 수 있는데 웹사이트의 도메인 전세계에서 유일무일한 식별자이기 때문에 이러한 중복의 문제를 피할 수 있다.

```
package org.opentutorials.javatutorials.packages.example1;
public class A {}
```
아래 코드는 위에서 정의한 클래스 A를 클래스 B에서 사용하는 예제다. 정상적으로 동작한다.
```
package org.opentutorials.javatutorials.packages.example1;
 
public class B {
    public static void main(String[] args) {
        A a = new A();
    }
}
```
* 이번에는 패키지를 바꿔보자.

```
package org.opentutorials.javatutorials.packages.example2;
 
public class B {
    public static void main(String[] args) {
        //클래스 A가 다른 패키지에 있기 때문에 로드 할 수 없다.
        A a = new A();
    }
}
```

* 위의 코드는 동작하지 않는다. 주석으로 처리한 A a = new A(); 부분에서 에러가 발생하기 때문이다. 그 이유는 여기서 사용하려는 클래스 A와 B가 서로 다른 패키지에 소속되어 있기 때문이다. 아래와 같이 코드를 고쳐서 이 문제를 해결할 수 있다.

```
package org.opentutorials.javatutorials.packages.example2;
import org.opentutorials.javatutorials.packages.example1.A;
 
public class B {
    public static void main(String[] args) {
        A a = new A();
    }
}
```

* 차이점은 아래와 같다.

* 서로 다른 패키지에 있는 클래스를 가져오려면 import를 통해서 다른 패키지의 클래스를 현재의 소스코드로 불러와야 한다. 만약 특정 패키지에 있는 모든 클래스를 로드하고 싶다면 아래와 같이 하면 된다.

```
package org.opentutorials.javatutorials.packages.example2;
import org.opentutorials.javatutorials.packages.example1.*;
 
public class C {
    public static void main(String[] args) {
        A a = new A();
    }
}
```

* 차이점은 아래와 같다. *는 '모든'이라는 뜻이다.

