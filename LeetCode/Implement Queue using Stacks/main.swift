class MyQueue {

	private var st: [Int]
	
	init() {
		st = [Int]()
	}
	
	func push(_ x: Int) {
		var temp = [Int]()
		while !st.isEmpty {
			temp.append(st.removeLast())
		}
		st.append(x)
		while !temp.isEmpty {
			st.append(temp.removeLast())
		}
	}
	
	func pop() -> Int {
		return st.removeLast()
	}
	
	func peek() -> Int {
		return st.last ?? -1
	}
	
	func empty() -> Bool {
		return st.isEmpty
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */