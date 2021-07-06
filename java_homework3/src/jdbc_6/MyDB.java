package jdbc_6;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
@SuppressWarnings("unused")
public class MyDB {
	
	ServerSocket ss;
	Socket cs;
		
		private static final String MYSQL_USERNAME = "root";
		private static final String MYSQL_PASSWORD = "123456";
		private static final String MYSQL_DATABASE_SERVER = "mysql-user.muc";
		private static final String MYSQL_DATABASE_NAME = "myUniversity";
		
		private static Connection con;
		static String sqlInsert="insert into metropolises " +"VALUES(\"Rostov-on-Don\",\"Europe\",1052000)";
		static String str="select *from metropolises";
		static {
			try {
				Class.forName("com.mysql.cj.jdbc.Driver");
				String url = "jdbc:mysql://localhost:3306/myUniversity?useSSL=false&serverTimezone=UTC";
				con = DriverManager.getConnection(url, MYSQL_USERNAME, MYSQL_PASSWORD);
				System.out.println( "���������ɹ�!" );
				  System.out.println( "�������ݿ�ɹ�!" );
				  Statement st = con.createStatement();
			        System.out.println( "����Statement�ɹ�!" );
				  
			       
			} catch (SQLException e) {
				e.printStackTrace();
				System.err.println("student: Update the MySQL constants to correct values!");
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
				System.err.println("student: Add the MySQL jar file to your build path!");
			}
		}
		
		public static Connection getConnection() {
			return con;
		}
		
		public static void close() {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		public ResultSet sh(ResultSet set) throws SQLException
		{
			 Statement st = con.createStatement();
			set=st.executeQuery( str );
			return set;
		}
		public void ins(String s1,String s2,String s3) throws SQLException
		{
			Statement st = con.createStatement();
			String sp="INSERT INTO metropolises VALUES("+"'"+s1+"'"+","+"'"+s2+"'"+","+"'"+s3+"'"+")";

		        System.out.println("��������ݳɹ�");
		}
		public void get_inform()
		{
			try{ 
	    		try {
	        	  ss = new ServerSocket(6666); //����һ��ServerSocket�����ڶ˿�6666
	    		}catch(IOException e){
	    			System.err.println("Failed to creat Socket");
	    			System.exit(1);
	    		}
	    		System.out.println("Server is ready...");
	    		try{
	        	  cs = ss.accept(); //������accept()������ʱ׼����������һ��Client�����󣬷���һ��Socket����    	 
	    		}catch (IOException e) {
	    			System.err.println("Accept failed.");
	    			System.exit(1);
	    		}
	    		System.out.println("Server is receiving msg from "+ss.getInetAddress()+":"+cs.getPort());
	         
	    		//��Socket��������������������BufferedReader����
	            InputStreamReader rs=new InputStreamReader(cs.getInputStream());//��������
	            BufferedReader is=new BufferedReader(rs); 
	          
	            //��Socket�������������������PrintWriter����
	            PrintWriter os = new PrintWriter(cs.getOutputStream(),true);
	            
	          
	            
	          //��Socket�ж�������Client�����ݲ��������Ļ
	           
	            
	            String []s=new String[3];
	            
	            int i;
	            
	            	
	            	
	            for(i=0;i<3;i++)
	            {
	            	 String line = is.readLine();
	 	            System.out.println("Client msg is:"+line);
	 	            s[i]=line;
	 	          
	 	            
	            }
	            os.println("����������");
	            
	            try {
					Class.forName("com.mysql.cj.jdbc.Driver");
					
					String url = "jdbc:mysql://localhost:3306/myUniversity?useSSL=false&serverTimezone=UTC";
					con = DriverManager.getConnection(url, MYSQL_USERNAME, MYSQL_PASSWORD);
					Statement st = con.createStatement();
					String sp="INSERT INTO metropolises(metropolis,continent,population) VALUES("+"'"+s[0]+"'"+","+"'"+s[1]+"'"+","+"'"+s[2]+"'"+")";
					 st.executeUpdate(sp);
					 os.println("��������ݳɹ�");
			        System.out.println("��������ݳɹ�");
			        
				} catch (SQLException e2) {
					// TODO Auto-generated catch block
					e2.printStackTrace();
				} catch (ClassNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
	            
	          
	        	
	        	
					
				 //����ѭ��
	            is.close(); //�ر�������
	            os.close(); //�ر������
	            cs.close(); //��һ���ͻ�ͨ����ϣ��ر�Client socket
	            ss.close();//�ر�server socket
		
	           
	    	} //
			 catch (IOException ie)
			{
		            ie.printStackTrace();
		    }//���ս���
			
			
		    
		}
		
		public static void main(String[] args) 
		{
			 MyDB k=new MyDB();
			 k.get_inform();
		}
}
		
		
	



