# Class Path

* IDE(eclipse, intellij)를 사용하지 않고 운영체제의 기본 에디터를 사용해보자.

### 클래스 패스

* 빈 디렉터리에 아래와 같이 코드를 작성한다. 아래 예제의 파일명은 ClasspathDemo.java 이다. 

```
class Item{
}
 
class ClasspathDemo {
}
```
컴파일을 하면, ```javac ClasspathDemo.java```
그 결과 두 개의 클래스 파일이 생성된다.

```
ClasspathDemo.class
Item.class
```

* 즉 클래스 하나는 하나의 클래스 파일이 된다는 것을 알 수 있다.


### 클래스의 경로

* ClasspathDemo2.java을 만들고 내용을 아래와 같이 한다.

```
class Item2{
    public void print(){
        System.out.println("Hello world");  
    }
}
 
class ClasspathDemo2 {
    public static void main(String[] args){
        Item2 i1 = new Item2();
        i1.print();
    }
}
```

* 컴파일을 한다. ```javac ClasspathDemo2.java```
* 그리고 현재 디렉터리 하위에 lib을 만들고 여기에 Item2.class 파일을 이동한다. 현재 디렉터리에는 Item2.class 파일이 없어야 한다. 그리고 ClasspathDemo2를 실행한다. ```java ClasspathDemo2```
* 아래와 같은 결과가 출력된다.

```
directory>java ClasspathDemo2
Exception in thread "main" java.lang.NoClassDefFoundError: Item2
        at ClasspathDemo2.main(ClasspathDemo2.java:9)
Caused by: java.lang.ClassNotFoundException: Item2
        at java.net.URLClassLoader$1.run(Unknown Source)
        at java.net.URLClassLoader$1.run(Unknown Source)
        at java.security.AccessController.doPrivileged(Native Method)
        at java.net.URLClassLoader.findClass(Unknown Source)
        at java.lang.ClassLoader.loadClass(Unknown Source)
        at sun.misc.Launcher$AppClassLoader.loadClass(Unknown Source)
        at java.lang.ClassLoader.loadClass(Unknown Source)
        ... 1 more
```

* 이것은 item.class 파일이 현재 디렉터리에 존재하지 않기 때문에 찾을 수 없다는 메시지다. 아래와 같이 실행해서 이 문제를 해결할 수 있다.
```java -classpath ".;lib" ClasspathDemo2```

* 리눅스, OSX와 같은 유닉스 계열의 시스템이라면 아래와 같이 콜론을 사용해야 한다.
```java -classpath ".:lib" ClasspathDemo2```

* 옵션 -classpath는 자바를 실행할 때 사용할 클래스들의 위치를 가상머신에게 알려주는 역할을 한다. -classpath의 값으로 사용된 ".;lib"를 살펴보면, 
  * . : 현재 디렉터리에서 클래스를 찾는다는 뜻이다.
  * ; : 경로와 경로를 구분해주는 구분자
  * lib : 현재 디렉터리에 없다면 현재 디렉터리의 하위 디렉터리 중 lib에서 클래스를 찾는다는 의미다.

* 만약 .을 제외한다면 어떻게 될까? 다음과 같은 오류가 발생할 것이다. ```F:\tmp\java>java -classpath "lib" ClasspathDemo 오류: 기본 클래스 Classpath을(를) 찾거나 로드할 수 없습니다.```

* 디렉터리 lib 아래에 있는 Item.class 파일을 찾았는데 정작 현재 디렉터리에 있는 ClasspathDemo.class 파일은 찾을 수 없기 때문이다.

* 이와 같이  클래스 패스라는 것은 자바를 실행할 때 클래스의 위치를 지정하는 역할을 하는 것이다. 클래스 패스는 자바 애플리케이션이 사용하고 있는 클래스가 여러 경로에 분산되어 있을 때 유용하게 사용할 수 있는 방법이다.

* 지금까지는 자바를 실행할 때 클래스 패스를 지정하는 방법을 알아봤다. 실행 할 때마다 클래스 패스를 지정하는 것이 귀찮다면 클래스 패스를 시스템의 환경변수로 지정하면 된다.

### 환경변수

* 환경변수는 운영체제에 지정하는 변수로 자바 가상머신과 같은 애플리케이션들은 환경변수의 값을 참고해서 동작하게 된다. 자바는 클래스 패스로 환경변수 CLASSPATH를 사용하는데 이 값을 지정하면 실행할 때마다 -classpath 옵션을 사용하지 않아도 되기 때문에 편리하다. 하지만 운영체제를 변경하면 클래스 패스가 사라지기 때문에 이식성면에서 불리할 수 있다.

* 운영체제 별로 환경변수를 설정하는 방법은 자바를 설치하는 방법에서 다루기 때문에 이것을 참고하자.
