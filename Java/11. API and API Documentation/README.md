# API와 API 문서 보는 법

### 기본 패키지와 사용자 정의 로직

```System.out.println(1);```

* 지금까지 무수히 많은 예제에서 사용했던 코드다. 이것이 화면에 어떤 내용을 출력하는 것이라는 건 이미 알고 있다. 하지만 도대체 우리가 정의한 적이 없는 이 명령은 무엇일까?를 생각해볼 때가 왔다. 문법적으로 봤을 때 println은 메소드가 틀림없다. 그런데 메소드 앞에 Sytem.out이 있다. System은 클래스이고 out은 그 클래스의 필드(변수)이다. 이 필드가 메소드를 가지고 있는 것은 이 필드 역시 객체라는 것을 알 수 있다. 그리고 System을 인스턴스화한적이 없음에도 불구하고 필드 out에 접근할 수 있는 것은 out이 static이라는 것을 암시한다.

* 그럼 System 클래스는 어디서 나타난 것일까? 아래의 코드를 보자.

```
package org.opentutorials.javatutorials.library;
public class LibraryDemo1 {
    public static void main(String[] args) {
        System.out.println(1);
    }
}
```

* 아래의 코드는 위의 코드와 같다.

```
package org.opentutorials.javatutorials.library;
import java.lang.*;
public class LibraryDemo1 {
    public static void main(String[] args) {
        System.out.println(1);
    }
}
```

* import java.lang.*;이 보이는가? 패키지 java.lang은 자바 프로그래밍을 하기 위해서 필수적인 클래스들을 모아둔 패키지다. 따라서 사용자의 편의를 위해서 자동으로 로딩을 하고 있는 것이다.
클래스 System은 바로 이 java.lang의 소속이다.

* 자바 에플리케이션을 만든다는 것은 결과적으로 자바에서 제공하는 패키지들을 부품으로 조립해서 사용자 정의 로직을 만드는 과정이라고 할 수 있다. 

### API

* API란 자바 시스템을 제어하기 위해서 자바에서 제공하는 명령어들을 의미한다. Java SE(JDK)를 설치하면 자바 시스템을 제어하기 위한 API를 제공한다. 자바 개발자들은 자바에서 제공한 API를 이용해서 자바 애플리케이션을 만들게 된다. 패키지 java.lang.*의 클래스들도 자바에서 제공하는 API 중의 하나라고 할 수 있다.


### API 문서

* 자바 플랫폼 위에서 동작하는 자바 애플리케이션을 개발하는 개발자들은 자바 API를 사용하게 된다. 그런데 자바에서 제공하는 API는 방대하기 때문에 이것을 이용하기 위해서는 API의 목록과 사용법이 체계적으로 정리된 문서를 이용할 수 있어야 한다.
[API문서](http://docs.oracle.com/javase/)
