# Valid Ramge

* 유효범위
  * 변수와 메소드 같은 것들을 사용할 수 있는 것은 이름이 있기 때문이다. 아래 코드에서 left는 변수의 이름이고, sum은 메소드의 이름이다.
```
int left;
public void sum(){}
```

* 프로그램이 커지면 여러 가지 이유로 이름이 충돌하게 된다. 이를 해결하기 위해서 고안된 것이 유효범위라는 개념이다. 흔히 스코프(Scope)라고도 부른다.

```
class C2 {
    int v = 10;
 
    void m() {
        int v = 20;
        System.out.println(v);
    }
}
 
public class ScopeDemo8 {
 
    public static void main(String[] args) {
        C2 c1 = new C2();
        c1.m();
    }
 
}
```

* 결과는 20이다. 즉 메소드 안에서 선언된 변수 v가 지역 변수가 되면서 인스턴스 전역에서 유효한 인스턴스 변수 v의 값보다 우선순위가 높아지면서 20이 출력된 것이다.

```
이런 상황에서 메소드 m에서 인스턴스 변수 v에 접근하려면 어떻게 해야할까? this를 사용하면 된다. 아래 코드를 보자. 
class C3 {
    int v = 10;
 
    void m() {
        int v = 20;
        System.out.println(this.v);
    }
}
 
public class ScopeDemo9 {
 
    public static void main(String[] args) {
        C3 c1 = new C3();
        c1.m();
    }
 
}
this.v로 바뀌었다. 그 결과 메소드 m 안에서 인스턴스 변수 v를 사용할 수 있게 되었다. this는 인스턴스 자신을 의미하는 키워드라고 할 수 있다.
```
