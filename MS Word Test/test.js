var wrapper = document.getElementsByClassName("wrapper clearfix"); 
var div, p, btn; 
var q_time = []; var t_time = []; 
var answer = []; 
var big_timer, b_sec, b_min, b_hour; 
var sm_timer, s_sec, s_min, s_hour; 


function startTimer(mode) {
    if (mode == "end") {
        clearInterval(big_timer);
        return;
    }
	b_sec = 0; b_min = 0; b_hour = 0;
	document.getElementById('all-timer').innerHTML = b_sec + ' sek.';
	big_timer = setInterval(
			function () {
				if ((b_min > 58) && (b_sec > 58)) {
					b_hour++; b_min = 0; b_sec = 0;
					document.getElementById('all-timer').innerHTML = b_hour + ' st. ' + b_min + ' min. ' + b_sec + ' sek.';
                } else if ((b_hour != "0") && (b_sec > 58)) {
                    b_min++; b_sec = 0;
                    document.getElementById('all-timer').innerHTML = b_hour + ' st. ' + b_min + ' min. ' + b_sec + ' sek.';
                } else if (b_sec > 58) {
                    b_min++; b_sec = 0;
                    document.getElementById('all-timer').innerHTML = b_min + ' min. ' + b_sec + ' sek.';
                } else if (b_hour != "0") {
                    b_sec++;
                    document.getElementById('all-timer').innerHTML = b_hour + ' st. ' + b_min + ' min. ' + b_sec + ' sek.';
				} else if (b_min != "0") {
					b_sec++;
					document.getElementById('all-timer').innerHTML = b_min + ' min. ' + b_sec + ' sek.';
				} else {
					b_sec++;
					document.getElementById('all-timer').innerHTML = b_sec + ' sek.';
				}
			}, 1000);
}

function startQTimer(mode) {
    if (mode == "end") {
        clearInterval(sm_timer);
        return;
    }
	if (sm_timer) clearInterval(sm_timer);
	s_sec = 0; s_min = 0; s_hour = 0;
	document.getElementById('q-timer').innerHTML = s_sec + ' sek.';
	sm_timer = setInterval(
			function () {
                if ((s_min > 58) && (s_sec > 58)) {
                    s_hour++; s_min = 0; s_sec = 0;
                    document.getElementById('q-timer').innerHTML = s_hour + ' st. ' + s_min + ' min. ' + s_sec + ' sek.';
                } else if ((s_hour != "0") && (s_sec > 58)) {
                    s_min++; s_sec = 0;
                    document.getElementById('q-timer').innerHTML = s_hour + ' st. ' + s_min + ' min. ' + s_sec + ' sek.';
                } else if (s_sec > 58) {
                    s_min++; s_sec = 0;
                    document.getElementById('q-timer').innerHTML = s_min + ' min. ' + s_sec + ' sek.';
                } else if (s_hour != "0") {
                    s_sec++;
                    document.getElementById('q-timer').innerHTML = s_hour + ' st. ' + s_min + ' min. ' + s_sec + ' sek.';
                } else if (s_min != "0") {
                    s_sec++;
                    document.getElementById('q-timer').innerHTML = s_min + ' min. ' + s_sec + ' sek.';
                } else {
                    s_sec++;
                    document.getElementById('q-timer').innerHTML = s_sec + ' sek.';
                }
			}, 1000);
}


function clean() {
    if (wrapper[0].hasChildNodes()) {
        while (wrapper[0].childNodes.length > 0) {
            wrapper[0].removeChild(wrapper[0].childNodes[0]);
        }
    }
}


function getTime(finish_time) {
    var arr = finish_time.split(":");
    return arr[0] + " st. " + arr[1] + " min. " + arr[2] + " sec.";
}

function getPoints(points) {
	var sum = 0;
	for (var i = 0; i < points.length; i++) {
		sum += (+points[i].points);
	}
	return sum + "/15";
}

function getView(que) {
    clean();

    var span = document.createElement("span");
    span.innerHTML = "Jautajums: ";
    div.appendChild(span);

    var container = document.createElement("div");
    container.className = "container clearfix";
    wrapper[0].appendChild(container);

    var p = document.createElement("p");
    p.innerHTML = q[que].quest;
    container.appendChild(p);

    switch (q[que].optType) {
        case "radio":
        case "checkbox":
			if (q[que].extra) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
				var image = document.createElement("img");
				image.className = "question-img";
				image.src = q[que].extra;
				ansDiv.appendChild(image);
				container.appendChild(ansDiv);
			}
            for (var i = 0; i < q[que].opt.length; i++) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
                var input = document.createElement("input");
                input.type = q[que].optType;
                input.name = "option";
                input.value = q[que].opt[i];
                input.disabled = true;
                var label = document.createElement("label");
                label.innerHTML = q[que].opt[i];
                ansDiv.appendChild(input);
                ansDiv.appendChild(label);
                container.appendChild(ansDiv);

                if (input.type == "checkbox") {
                    for (var j = 0; j < answer[que].opt.length; j++) {
                        if (i === answer[que].opt[j]) {
                            input.checked = true;
                            for (var k = 0; k < q[que].ans.length; k++) {
                                if (input.value == q[que].ans[k]) {
                                    input.nextElementSibling.style.color = "green";
                                    input.nextElementSibling.style.fontWeight = "bold";
                                } else {
                                    input.nextElementSibling.style.color = "red";
                                }
                            }
                        }
                    }
                    for (var k = 0; k < q[que].ans.length; k++) {
                        if (input.value == q[que].ans[k]) {
                            input.nextElementSibling.style.color = "green";
                            input.nextElementSibling.style.fontWeight = "bold";
                        }
                    }

                } else if (input.type == "radio") {
                    if (answer[que].opt == i) {
                        input.checked = true;
                        if (input.value == q[que].ans) {
                            input.nextElementSibling.style.color = "green";
                            input.nextElementSibling.style.fontWeight = "bold";
                        } else {
                            input.nextElementSibling.style.color = "red";
                        }
                    }

                    if (input.value == q[que].ans) {
                        input.nextElementSibling.style.color = "green";
                        input.nextElementSibling.style.fontWeight = "bold";
                    }
                }
            }
            break;
        case "text":
			if (q[que].extra) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
				var image = document.createElement("img");
				image.className = "question-img";
				image.src = q[que].extra;
				ansDiv.appendChild(image);
				container.appendChild(ansDiv);
			}
            var ansDiv = document.createElement("div");
            ansDiv.className = "ans-block";
            var input = document.createElement("input");
            input.type = "text";
            input.name = "option";
            input.disabled = true;
            input.value = answer[que].value;
            ansDiv.appendChild(input);
            container.appendChild(ansDiv);

            if (input.value == q[que].ans) {
                input.style.borderColor = "green";
                input.style.borderStyle = "solid";
            } else {
                input.style.borderColor = "red";
                input.style.borderStyle = "solid";
                var error = document.createElement("span");
                error.className = "error";
                error.innerHTML = "Pareizā atbilde: " + q[que].ans;
                ansDiv.appendChild(error);
            }
            break;
        case "image":
            for (var i = 0; i < q[que].opt.length; i++) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
                var image = document.createElement("img");
                image.className = "question-img2";
                image.src = q[que].opt[i];
                image.name = "option";
                ansDiv.appendChild(image);
                container.appendChild(ansDiv);

                if (answer[que].opt == i)
                    if (i == q[que].ans)
                        image.style.border = "5px solid green";
                    else image.style.border = "2px solid red";

                if (i == q[que].ans)
                    image.style.border = "5px solid green";
            }
            break;
    }

    btn.innerHTML = "Atpakaļ";
    btn.onclick = function() {
        clean();
        summary();
    };
    container.appendChild(btn);
}

function saveAnswer(num) {
    var check = answer.length;
    var ans = document.getElementsByName("option");
    switch (ans[0].type) {
        case 'image':
            if (answer[answer.length-1].image == num-1)
                return;
            else {
                answer.push({opt: null, value: null, points: "0.0"});
                return;
            }
            break;
        case 'text':
            if (ans[0].value == q[num-1].ans) {
                answer.push({opt: 0, value: ans[0].value, points: "1.0"});
            } else answer.push({opt: 0, value: ans[0].value, points: "0.0"});
            break;
        case 'radio':
            for (var i = 0; i < ans.length; i++) {
                if (ans[i].checked) {
                    if (ans[i].value == q[num-1].ans) {
                        answer.push({opt: i, points: "1.0"});
                    } else answer.push({opt: i, points: "0.0"});
                }
            }
            break;
        case 'checkbox':
            var ansLen = q[num-1].ans.length;
            var points_plus = Math.floor((1 / ansLen) * 100) / 100;
            var points = 0, options = [];
            for (var i = 0; i < ans.length; i++) {
                if (ans[i].checked) {
                    var check = points;
                    for (var j = 0; j < ansLen; j++) {
                        if (ans[i].value == q[num-1].ans[j]) {
                            points += points_plus;
                        }
                    }
                    if (check == points) points -= points_plus;
                    options.push(i);
                }
            }
			if (points < 0) points = "0.0"; // check for negative number
            if (points == 0) points = "0.0"; // just to get more correct view
            if (points == 1) points = "1.0"; // just to get more correct view
            if (points == 0.99) points = "1.0"; // just to get round number
            answer.push({opt: options, points: points});
            break;
    }

    if (check == answer.length) answer.push({opt: null, value: null, points: "0.0"});
}

function summary () {

    clean();

    var h2 = document.createElement("h2");
    h2.innerHTML = "Pārskats";
    wrapper[0].appendChild(h2);

    var common_table = document.createElement("table");
    common_table.className = "summary-table";
    wrapper[0].appendChild(common_table);

    var time_tr = document.createElement("tr");
    common_table.appendChild(time_tr);
    var time_th = document.createElement("th");
    time_th.innerHTML = "Kopējais laiks";
    time_tr.appendChild(time_th);
	var punkti_th = document.createElement("th");
	punkti_th.innerHTML = "Kopējais punktu skaits";
	time_tr.appendChild(punkti_th);
    var time2_tr = document.createElement("tr");
    common_table.appendChild(time2_tr);
    var time_td = document.createElement("td");
    time_td.innerHTML = getTime(t_time[0]);
	var punkti_td = document.createElement("td");
	punkti_td.innerHTML = getPoints(answer);
    time2_tr.appendChild(time_td);
    time2_tr.appendChild(punkti_td);

    var table = document.createElement("table");
    table.className = "summary-table";
    wrapper[0].appendChild(table);

    var tr = document.createElement("tr");
    table.appendChild(tr);
    var th1 = document.createElement("th");
    th1.innerHTML = "Numurs";
    tr.appendChild(th1);
    var th2 = document.createElement("th");
    th2.innerHTML = "Laiks";
    tr.appendChild(th2);
    var th3 = document.createElement("th");
    th3.innerHTML = "Punkti";
    tr.appendChild(th3);
    var th4 = document.createElement("th");
    th4.innerHTML = "Pārskats";
    tr.appendChild(th4);

    for (var i = 0; i < q.length; i++) {
        tr = document.createElement("tr");
        table.appendChild(tr);
        var td1 = document.createElement("td");
        td1.innerHTML = i+1;
        tr.appendChild(td1);
        var td2 = document.createElement("td");
        td2.innerHTML = getTime(q_time[i]);
        tr.appendChild(td2);
        var td3 = document.createElement("td");
        td3.innerHTML = answer[i].points;
        tr.appendChild(td3);
        var td4 = document.createElement("td");
        tr.appendChild(td4);
        var link = document.createElement("a");
        link.innerHTML = "Pārskats";
        link.onclick = (function (currI) {
            return function() {
                getView(currI);
            }
        })(i);
        td4.appendChild(link)
    }

    var back = document.createElement("button");
    back.className = "start";
    back.style.margin = "10px 0";
    back.innerHTML = "Mēģināt vēlreiz";
    back.onclick = function () {
        t_time = [];
        q_time = [];
        answer = [];
        window.location.reload();
    };
    wrapper[0].appendChild(back);
}


function question(num) {
	if (num === "start") {
		num = "1";
		div = document.getElementsByClassName("container clearfix")[0];

		p = document.createElement("p"); 
		div.appendChild(p);

		btn = document.createElement("button"); 
		btn.className = "start";
		btn.innerHTML = "Nākošais";
		btn.onclick = function() {
            q_time.push(s_hour + ':' + s_min + ':' + s_sec); 
            saveAnswer(num);
            ++num;
            if (num == q.length) question("end");
            startQTimer();
			question(num.toString());
		};
	}

    if (num === "end") { 
        num = q.length;
        btn.innerHTML = "Pabeigt testu";
        btn.onclick = function() {
            q_time.push(s_hour + ':' + s_min + ':' + s_sec);
            t_time.push(b_hour + ':' + b_min + ':' + b_sec); 
            startTimer("end"); 
            startQTimer("end"); 
            saveAnswer(num);
            summary();
        };
    }

	if (div.hasChildNodes) { 
		while (div.childNodes.length > 1) {
			p.innerHTML = "";
			div.removeChild(div.childNodes[1]);
		}
	}

    p.innerHTML = q[num-1].quest;

    switch (q[num-1].optType) {
        case "radio":
        case "checkbox":
			if (q[num-1].extra) {
				var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
				var image = document.createElement("img");
				image.className = "question-img";
				image.src = q[num-1].extra;
				ansDiv.appendChild(image);
				div.appendChild(ansDiv);
			}
            for (var i = 0; i < q[num-1].opt.length; i++) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
                var input = document.createElement("input");
                input.type = q[num-1].optType;
                input.name = "option";
                input.value = q[num-1].opt[i];
                var label = document.createElement("label");
                label.innerHTML = q[num-1].opt[i];
                ansDiv.appendChild(input);
                ansDiv.appendChild(label);
                div.appendChild(ansDiv);
            }
            break;
        case "text":
			if (q[num-1].extra) {
				var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
				var image = document.createElement("img");
				image.className = "question-img";
				image.src = q[num-1].extra;
				ansDiv.appendChild(image);
				div.appendChild(ansDiv);
			}
            var ansDiv = document.createElement("div");
            ansDiv.className = "ans-block";
            var input = document.createElement("input");
            input.type = "text";
            input.name = "option";
            ansDiv.appendChild(input);
            div.appendChild(ansDiv);
            break;
        case "image":
            for (var i = 0; i < q[num-1].opt.length; i++) {
                var ansDiv = document.createElement("div");
                ansDiv.className = "ans-block";
                var image = document.createElement("img");
                image.className = "question-img2";
                image.src = q[num-1].opt[i];
                image.name = "option";
                image.type = "image";
                image.onclick = (function(currI) {
                    return function() {
                        if (currI == q[num-1].ans) answer.push({opt: currI, image: num-1, points: "1.0"});
                        else answer.push({opt: currI, image: num-1, points: "0.0"});
                        btn.onclick();
                    }
                })(i);
                ansDiv.appendChild(image);
                div.appendChild(ansDiv);
            }
            break;
    }

    div.appendChild(btn);
}


function start() {
	var container = document.getElementsByClassName("container clearfix")[0];
	while (container.hasChildNodes()) {
		container.removeChild(container.childNodes[0]);
	}

    question("start");
    startTimer();
    startQTimer();

}