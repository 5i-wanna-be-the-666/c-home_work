package java_homework_2_3;



import java.util.Iterator;
import java.util.List;

@SuppressWarnings("serial")
public class Interface_crudRobot extends Robot{
	
	void inser(List<AbstractRobot> A,AbstractRobot []t)//���
	{
		int i=0;
		for(i=0;i<t.length;i++)
		{
			A.add(t[i]);
			 System.out.println("��ӳɹ�");
		}
		if(i==0)
		{
			System.out.println("����Ϊ�գ����ʧ��");
		}
	}
	int find(List<AbstractRobot> A,AbstractRobot t)//����
	{
		int i=0;
		for (AbstractRobot str : A)
		 {
			 if(str.equals(t))
			 {
				 System.out.println("���ҳɹ�������λ��");
				return i;
			 }
			 i++;
		 }
		System.out.println("����ʧ�ܣ��û����˲�����");
		return -1;
		
	}
	
	void display(List<AbstractRobot> A)//��ʾ
	{
		
		for (AbstractRobot str : A)
		 {
			 System.out.println(str.toString());
		 }
	}
	
	 @SuppressWarnings("unused")
	void delete(List<AbstractRobot> A,AbstractRobot t)//ɾ��
	{
		 int i=0;
		 int flag=0;
		 Iterator<AbstractRobot> it_b=A.iterator();
		 
			 while(it_b.hasNext()){
		            AbstractRobot a=it_b.next();
		            if (a.equals(t)) {
		                it_b.remove();
		                flag=1;
		            }
		        }
		 
		
		 
		 if(flag==0)
		 {
			 System.out.println("ɾ��ʧ�ܣ����������������");
		 }
		 
		 if(flag==1)
		 {
			 System.out.println("ɾ���ɹ�");
		 }
	}
	 
	void update(List<AbstractRobot> A, AbstractRobot t,AbstractRobot n)//����
	{
		int i=0;
		int flag=0;
		 for (AbstractRobot str : A)
		 {
			 if(str.equals(t))
			 {
				 A.set(i,n);
				 flag=1;
			 }
			 i++;
		 }
		 
		 if(flag==0)
		 {
			 System.out.println("����ʧ�ܣ����������������");
		 }
		 
		 if(flag==1)
		 {
			 System.out.println("���³ɹ�");
		 }
	}
}
