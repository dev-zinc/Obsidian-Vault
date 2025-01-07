제네릭은 편리하지만 자칫하면 타입지옥을 만들어버리곤 한다.

최근 한 달 간, 왜 그랬는지는 몰라도 추상 객체의 타입을 명시적으로 적어내려고 부단히 노력했다. 그러다가 나도 이러한 괴물을 탄생시키게 되었는데...

```Java
public interface Quest<Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> {
	
}

public interface QuestProcess<Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> {
	
}

public interface QuestObjective<Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> {
	
}
```

각 퀘스트를 구현하는 클래스와 일대일 대응하는 열거형 QuestType을 선언하였고, 기존에 아래와 같은 방식으로 각 구현 객체를 가져오는 코드가 있었다.

```Java
// QuestProvider
public Quest<?, ?, ?> getQuest(QuestType questType) {
	return ...
}
```

문제는 여기에서 발생하였다. 리턴타입의 명확성을 해치는 저 간악한 와일드카드를 참을 수 없는 병이 생겨버린 나머지... 무리한 시도를 하게 된 것이다.

```Java
public <Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> getQuest(QuestType questType) {
	return ...
}
```

이를 구현해내기 위해 여러 가지 시도를 해보았다. 

```Java
//Enum에서 정적 선언 객체로의 변경

public class QuestType<Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> {
	public static final QuestType EXAMPLE_TYPE = new QuestType(ExampleQuest.class);

	private final Class<Q> questClass;

	//...
}


//QuestProvider
public <Q extends Quest<Q, P, O>, P extends QuestProcess<Q, P, O>, O extends QuestObjective<Q, P, O>> getQuest(QuestType questType) {
	Quest<?, ?, ?> quest = // get original Quest Object;

	return questType.cast(quest);
}
```

여러 방법을 고민하면서 많은 생각이 들었다. 

굳이 이 객체가 무슨 타입인지 알아야 할 필요가 있을까?


결과적으로, QuestType은 해당 퀘스트의 타입 정보를 반영하고 있는 객체이다. 애초에 타입이 밝혀져야 작동 가능한 구조라면 그게 잘못된 설계가 아니었을까 하고 생각한다.

전부 갈아엎고 다시 만들었다.