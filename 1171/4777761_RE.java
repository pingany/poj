package test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class Main {
	public static final char mapping[]= new char[128];

	static{
		mapping[(int)'a'] = 2;
		mapping[(int)'b'] = 5;
		mapping[(int)'c'] = 4;
		mapping[(int)'d'] = 4;
		mapping[(int)'e'] = 1;
		mapping[(int)'f'] = 6;
		mapping[(int)'g'] = 5;
		mapping[(int)'h'] = 5;
		mapping[(int)'i'] = 1;
		mapping[(int)'j'] = 7;
		mapping[(int)'k'] = 6;
		mapping[(int)'l'] = 3;
		mapping[(int)'m'] = 5;
		mapping[(int)'n'] = 2;
		mapping[(int)'o'] = 3;
		mapping[(int)'p'] = 5;
		mapping[(int)'q'] = 7;
		mapping[(int)'r'] = 2;
		mapping[(int)'s'] = 1;
		mapping[(int)'t'] = 2;
		mapping[(int)'u'] = 4;
		mapping[(int)'v'] = 6;
		mapping[(int)'w'] = 6;
		mapping[(int)'x'] = 7;
		mapping[(int)'y'] = 5;
		mapping[(int)'z'] = 7;
		
	}
	

	public static void main(String[] args) {
//		try {
//			System.setIn(new FileInputStream(new File("input.txt")));
//		} catch (FileNotFoundException e1) {
//			// TODO Auto-generated catch block
//			e1.printStackTrace();
//		}
//		URL url = Main.class.getClassLoader().getResource("input.txt");
////		FileInputStream fis =null;
//		try {
//			fis = new FileInputStream(new File(url.toURI()));
//		} catch (FileNotFoundException e1) {
//			e1.printStackTrace();
//		} catch (URISyntaxException e1) {
//			e1.printStackTrace();
//		}
		BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
		String line;
		List<String> list = new ArrayList<String>();
		List<String> usefulList = new ArrayList<String>();
		Map<Character,Integer> timesMaping = new TreeMap<Character,Integer>();
		try {
			int i = 0;
			while((line=br.readLine())!=null){
				i++;
				if(i==1){
					for(int j=0;j<line.length();j++){
						timesMaping.put(line.charAt(j), appearTimes(line.charAt(j),line));
					}
				}else{
					if(line.equals(".")){
						break;
					}else{
						list.add(line);
					}
				}
			}
			for(int n=0; n<list.size(); n++){
				for(int k=0;k<list.get(n).length();k++){
					Character chara = list.get(n).charAt(k);
					int times = appearTimes(chara,list.get(n));
					if(timesMaping.get(chara)==null||times>timesMaping.get(chara)){
						list.remove(n);
						break;
					}
				}
			}
			if(list.size()>0){
				for(String letter : list){
					label01 : for(String letter2 : list){
						if(!letter.equals(letter2)){
							String uninLetter  = letter+letter2;
							for(int m=0;m<uninLetter.length();m++){
								Character chara = uninLetter.charAt(m);
								int times = appearTimes(chara,uninLetter);
								if(timesMaping.get(chara)==null || times>timesMaping.get(chara)){
									break label01;
								}else if(times<=timesMaping.get(chara)){
									usefulList.add(uninLetter);
									break label01 ;
								}
							}
						}
					}
				}
			}
			
			if(usefulList.size()>0){
				System.out.println(getMaxNum(usefulList));
			}else if(list.size()>0){
				System.out.println(getMaxNum(list));
			}else{
				System.out.println("没有符合条件的字符串");
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	private static int appearTimes(Character c ,String line){
		int times = 0;
		for(int i=0;i<line.length();i++){
			if(c==line.charAt(i)){
				times++;
			}
		}
		return times;
		
	}

	private static int getMaxNum(List<String> list){
		int maxNum = 0;
		for(String str : list){
			int result = 0;
			for(int i=0;i<str.length();i++){
				result += mapping[str.charAt(i)];
			}
			if(maxNum<=result)
				maxNum = result;
		}
		return maxNum;
	}
}
