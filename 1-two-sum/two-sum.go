func twoSum(nums []int, target int) []int {
    for i,value:= range(nums){
        for j,value1:=range(nums){
            if i!=j && (value+value1)== target{
                return []int{i,j}
            }
        }
    }
    return nil
}