package java_homework_2_6;

import java.io.BufferedReader;

import java.io.FileReader;
import java.io.IOException;

import java.math.BigDecimal;

public class Searching_Engine 
{
	int wen_dang_shu;
	String []Vocabulary;
    ju_zhen wen_dang;
    Searching_Engine()
    {
    	this.wen_dang_shu=0;
    	
    	
    }
    public double Three_decimal_places(double f) //������λС���ĺ���
    {
        BigDecimal bg = new BigDecimal(f);
        @SuppressWarnings("deprecation")
		double f1 = bg.setScale(3, BigDecimal.ROUND_HALF_UP).doubleValue();
        return f1;
    }
  
    
	
	@SuppressWarnings({ "unused", "resource" })
	void creat(Searching_Engine s,String []wen_name) throws IOException
	{
		int i=0;
		FileReader ci = new   FileReader("Vocabulary.txt");//����������
		  BufferedReader oci = new BufferedReader(ci);
		  String str;
		 while((str=(String)oci.readLine())!=null)
		 {
			
			//ȷ���ʱ��еĵ��ʸ�������������ĸ��������Ľ���
			 i++;
			
		 }
		
		 FileReader ci2 = new   FileReader("Vocabulary.txt");//����������
		  BufferedReader oci2 = new BufferedReader(ci2);
		 
		int n=wen_name.length;
		int j=0;
		this.wen_dang_shu=n;//�ĵ�������
	    this.Vocabulary=new String[i];//�ʱ�ĳ���
	    this.wen_dang=new ju_zhen(n,i);//������½�
		 for(j=0;j<i;j++)
		 {
			 this.Vocabulary[j]=(String)oci2.readLine();//�����˴ʱ�
			
		 }
		 
		 
		 
		String yong=new String();//������ʱ�����ַ�����
		int wen_wei=0;//��¼�ĵ��±�ı���
		 for(wen_wei=0;wen_wei<wen_name.length;wen_wei++)
		 {
			 FileReader dang = new FileReader(wen_name[wen_wei]);//����������
			 BufferedReader odang = new  BufferedReader(dang);
			 
			 StringBuilder result=new StringBuilder();
			 while(( yong=odang.readLine())!=null)
			 {
				result.append(yong);
				
				result.append('\n');
			 }
			 
			  yong=result.substring(0,result.length());//�����ļ������дʻ㵽yong�ַ�����
			
			    char []use=new char[yong.length()];
			    use=yong.toCharArray();
			   int word_shu=0;
			   for(int u=0;u<use.length;u++)
			   {
				   if(use[u]=='\n')
				   {
					   word_shu++;
				   }
				   if(use[u]==' ')
				   {
					   word_shu++;
					   while(use[u]==' ')//�������˵�һ��֮��Ŀո�
						   u++;
					  
				   }
				
			   }//��yongת��Ϊ�ַ�����ͳ��\nҲ���ǵ��ʵ�����
			  
			   
			   for(int Vocabulary_wei=0;Vocabulary_wei<this.Vocabulary.length;Vocabulary_wei++)
			   {
				   int wei=-2;
				   int ci_shu=0;
				   String yy=new String();
				   yy=yong;
				   while(wei!=-1 && yy!=null && yy.length()!=0)
					  {
					 
					
						wei=yy.indexOf(this.Vocabulary[Vocabulary_wei]); 
						if(wei!=-1)
						{
							ci_shu++;//�ҵ��˾��ô�����һ
							yy=yy.substring(wei+this.Vocabulary[Vocabulary_wei].length());//�������ڵ���������ٴμ���
						}
						 
						  
					  }
				
				   this.wen_dang.zu[wen_wei+1][Vocabulary_wei+1]=(double)ci_shu/word_shu;//����ȷ���˾����У�i��j���Ĵ�С����һ��Ϊ�������ӵ�һ�е�һ�п�ʼ���ȽϺÿ�
				   this.wen_dang.zu[wen_wei+1][Vocabulary_wei+1]=this.Three_decimal_places(this.wen_dang.zu[wen_wei+1][Vocabulary_wei+1]);
			   }
			   
			  
			  
			   
			   
		 }
		 
		
	}
	public void print()//����洢����ĺ���
	{
		for(int k=1;k<=this.wen_dang_shu;k++)
		   {
			   for(int p=1;p<=this.Vocabulary.length;p++)
			   {
				   System.out.print(this.wen_dang.zu[k][p]+" ");
			   }
			   System.out.println();
		   }
	}
	
	public String find(String s,String []wen_name)
	{
		 int wei=-2;
		   int ci_shu=0;
		   ju_zhen xiang_liang=new ju_zhen(1,this.Vocabulary.length+1);//������
		   double []result=new double [this.Vocabulary.length+1];//�洢����������˵Ľ��
		   String yy=new String();
		  
			  
			   for(int Vocabulary_wei=0;Vocabulary_wei<this.Vocabulary.length;Vocabulary_wei++)
			   {
				   ci_shu=0;
				   yy=s;
				   wei=-2;
				   while(wei!=-1 && yy!=null && yy.length()!=0)
					  {
					 
						wei=yy.indexOf(this.Vocabulary[Vocabulary_wei]); 
						if(wei!=-1)
						{
							ci_shu++;//�ҵ��˾��ô�����һ
							yy=yy.substring(wei+this.Vocabulary[Vocabulary_wei].length());//�������ڵ���������ٴμ���
						}
						
						  
					  }
				   xiang_liang.zu[1][Vocabulary_wei+1]=ci_shu;
				 
			   }
			   System.out.println();
		   
		   
		   double sum_hang=0;
		   int return_file_wei=0;//�����ļ�������ѡ���ļ����±�
		   double most_close=0;//������ʾ��ӽ�������������
		   for(int lie_chang=0;lie_chang<wen_name.length;lie_chang++)
		   {
			   sum_hang=0.0;
			   for(int hang_chang=1;hang_chang<=this.Vocabulary.length;hang_chang++)
			   {
				   sum_hang+= xiang_liang.zu[1][hang_chang]*this.wen_dang.zu[lie_chang+1][hang_chang];
			   }
			   result[lie_chang]=this.Three_decimal_places(sum_hang);//�������������ԭ���ľ����д洢����ֵ��˵Ľ��
			   if(most_close<result[lie_chang])
			   {
				   most_close=result[lie_chang];
				   return_file_wei=lie_chang;
			   }
			 
		   }
		   
		
		return wen_name[return_file_wei];
		
	}
	public static void main(String []arug) throws IOException,	    
	ClassNotFoundException 
	{
		String []wen_name=new String[2];
		wen_name[0]=new String("ofile1.txt");//�½��ļ�����string����
		wen_name[1]=new String("ofile2.txt");
		Searching_Engine search=new Searching_Engine();
		search.creat(search,wen_name);//����������ĺ���
		search.print();
		System.out.println(search.find("green apple blue sky", wen_name));//ȷ���������ݼ������ĺ���
		
	
	}

	

}
