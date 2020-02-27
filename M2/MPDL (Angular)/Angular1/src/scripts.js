

function list() {
    return [
        { name: 'Angular', value: 5, trainer : 'mostefai' },
        { name: 'React', value: 3 },
        { name: 'Vue', value: -1 }

    ]
}

function domTest() {
    var nd = document.createElement("ul");

    var lst = list();
    for (var i = 0; i < lst.length; i++) {
        console.log(lst[i]);
        var tag = document.createElement("li");
        var txt = document.createTextNode(lst[i].name + lst[i].value + lst[i].trainer);
        tag.appendChild(txt); 
        nd.appendChild(tag);
    }
    var elt = document.getElementById("testDiv");
    elt.childNodes = new Array();
    elt.appendChild(nd);
}