int stray(std::vector<int> numbers) {
	int many = numbers[0],only = numbers[1];
	for(int i = 2;i<numbers.size();i++){
		if(many==only){
			only=numbers[i];
		}else if(numbers[i]==only){
			only = many;
			many = numbers[i];
			break;
		}
	}
    return only;
};