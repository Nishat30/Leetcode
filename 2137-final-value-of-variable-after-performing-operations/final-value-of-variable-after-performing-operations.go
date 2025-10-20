func finalValueAfterOperations(operations []string) int {
    total:=0
    for _,char:=range operations{
        if char=="--X" || char == "X--"{
            total--
        }else{
            total++
        }
    }
    return total
}