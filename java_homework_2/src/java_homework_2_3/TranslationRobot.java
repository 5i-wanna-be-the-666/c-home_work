package java_homework_2_3;

@SuppressWarnings("serial")
public  class TranslationRobot extends AbstractRobot{

	TranslationRobot()
	{
		super();
	}
	TranslationRobot(String name,float a,int b,float c)
	{
		super(name,a,b,c);
	}
	
	void greet() //ʵ�ֵ�greet����
	{
		this.talk("Welcome to TranslationRobot");
		
	}
	String zhong(String substitute)
	{
		return substitute;
	}
	@SuppressWarnings("unused")
	void translate(String substitute)//����
	{
		String phrase=zhong(substitute);
		this.talk(substitute);
	}

	void charge(float amount) //˫�����
	{
		this.powerLevel+=2*amount;
	}
	
}
