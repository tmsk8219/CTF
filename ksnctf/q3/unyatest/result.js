function init(){
	var p = Array(70,152,195,284,475,612,791,896,810,850,737,1332,1469,1120,1470,832,1785,2196,1520,1480,1449);
	for(var i = 0; i < p.length; i++){
		console.log(String.fromCharCode(p[i] / (i + 1)));
	}
}