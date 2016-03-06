import java.util.*;
/**
 * Postfix Expression Evaluation
 */
class Main {

	Stack<Integer> 			stack;
	Queue<Integer> 			queue;
	PriorityQueue<Integer>  pQueue;
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String line;
		String values[];
		int cases = in.nextInt();
		
		Main m = new Main();
		
		in.nextLine();
		while(cases-- != 0){
			m.stack =new Stack<Integer>();
			m.queue =new LinkedList<Integer>();
			m.pQueue = new PriorityQueue<Integer>();
			line = in.nextLine();
			values = line.split(" ");
			for(String s : values){
				if(s.equals("-")){
					m.process('-');
				}
				else if(s.equals("+")){
					m.process('+');
				}
				else if(s.equals("*")){
					m.process('*');					
				}
				else{
					m.addValue(Integer.parseInt(s));
				}
			}
			System.out.println(m.stack.peek()+" "+m.queue.peek()+" "+m.pQueue.peek());
		}
		
		
	}
	
	private void addValue(int val){
		stack.push(val);
		queue.offer(val);
		pQueue.offer(val);
	}
	
	private void process(char op){
		int xs,ys, xq,yq, xp,yp;
		xs = stack.pop();
		ys = stack.pop();
		
		xq = queue.poll();
		yq = queue.poll();
		
		xp = pQueue.poll();
		yp = pQueue.poll();
		switch(op){
		case '-':
			//STACK
			stack.push(ys-xs);
			//QUEUE
			queue.offer(yq-xq);
			//PRIORITY QUEUE
			pQueue.offer(yp-xp);
			break;
		case '+':
			//STACK
			stack.push(ys+xs);
			//QUEUE
			queue.offer(yq+xq);
			//PRIORITY QUEUE
			pQueue.offer(yp+xp);
			break;
		case '*':
			//STACK
			stack.push(ys*xs);
			//QUEUE
			queue.offer(yq*xq);
			//PRIORITY QUEUE
			pQueue.offer(yp*xp);
			break;
		}
		
	}
}

/**

5
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -



*/
