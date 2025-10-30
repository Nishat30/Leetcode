func minNumberOperations(target []int) int {
    sum:=target[0]
    for i:=1; i<len(target); i++{
        if target[i]>target[i-1]{
            sum+=target[i]-target[i-1]
        }
    }
    return sum
}