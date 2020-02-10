function cacher(){
	var x = document.getElementById("top_barre").getElementsByTagName("ul")[0];
	if(x.style.display == "none") x.style.display="block";
	else x.style.display="none";
}