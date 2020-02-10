function quiz(){
	var solutions = [0,1,0,2,2,1,0,2,2,1,1,1,0,2,0,1,0,0,1,2];
	var result = 0;
	for(var i=0;i<20;i++){
		var user = document.getElementsByName("Q"+(i+1));
		var col = document.getElementById("Q"+(i+1)).getElementsByTagName("label");
		for(var j=0;j<3;j++){
			if(user[j].checked){
				if(j==solutions[i]) result++;
				else col[j+1].style.color = "red";
			}
			col[solutions[i]+1].style.color = "green";
			user[j].setAttribute("disabled","disabled");
		}
	}
	var res = document.getElementById("result");
	res.innerText = "Votre note: "+result+" / 20";
	if(result>=10) res.style.color="green";
	else res.style.color="red";
}