const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
</head>

<style>

</style>

<script>
        function UpdateData()
    {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function (){
            if(this.readyState == 4 && this.status == 200)
            {
                var DataVDK = xhttp.responseText;
                console.log("Dữ liệu VDK:" + DataVDK);

                var DataJson = JSON.parse(DataVDK);

                if(DataJson.ND != null)
                {
                    document.getElementById("nhietdo").innerHTML = DataJson.ND;
                }

                if(DataJson.DA != null)
                {
                    document.getElementById("doam").innerHTML = DataJson.DA;
                }
                {
                    if(DataJson.TB1 == 1)
                    {
                        document.getElementById("tttb1").innerHTML = "ON";
                    }
                    else if (DataJson.TB1 == 0)
                    {
                        document.getElementById("tttb1").innerHTML = "OFF";
                    }
                }

                if(DataJson.TB2 != null)
                {
                    if(DataJson.TB2 == 1)
                    {
                        document.getElementById("tttb2").innerHTML = "ON";
                    }
                    else if (DataJson.TB2 == 0)
                    {
                        document.getElementById("tttb2").innerHTML = "OFF";
                    }
                }
            }
        }
        xhttp.open('GET','/Update',true);
        xhttp.send();

        setTimeout(function(){ UpdateData()}, 1000);
    }
function GetButtonData(data)
{
    switch (data)
    {
        case 1:
            console.log("Button thiết bị 1 ONCLICK");
            var thietbi1 = document.getElementById("tttb1").innerHTML;

            console.log(thietbi1);

            if(thietbi1 == "ON")
            {
                var tx = "A0B";
                var xhttp = new XMLHttpRequest();
                xhttp.open("GET","/Button?Button="+tx, true);
                xhttp.send();
            }
            else if(thietbi1 == "OFF")
            {
                var tx = "A1B";
                var xhttp = new XMLHttpRequest();
                xhttp.open("GET","/Button?Button="+tx, true);
                xhttp.send();
            }
            break;
        case 2:
            console.log("Button thiết bị 2 ONCLICK");
            var thietbi2 = document.getElementById("tttb2").innerHTML;

            console.log(thietbi2);

            if(thietbi2 == "ON")
            {
                var tx = "C0D";
                var xhttp = new XMLHttpRequest();
                xhttp.open("GET","/Button?Button="+tx, true);
                xhttp.send();
            }
            else if(thietbi2 == "OFF")
            {
                var tx = "C1D";
                var xhttp = new XMLHttpRequest();
                xhttp.open("GET","/Button?Button="+tx, true);
                xhttp.send();
            }
            break;
    }
}

function GetInPut(data)
{
    switch(data)
    {
        case 1:
            var C1 ="D"+ document.getElementById("ngay_bd").value +"F";
            console.log(C1);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C1, true);
            xhttp.send();
            

            var C2 = "G"+ document.getElementById("ngay_kt").value +"H";
            console.log(C2);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C2, true);
            xhttp.send();

            var C3 ="J"+ document.getElementById("list").value +"K";
            console.log(C3);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C3, true);
            xhttp.send();

            var C4 ="K"+ document.getElementById("time_bom").value +"L";
            console.log(C4);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C4, true);
            xhttp.send();

            var C5 ="L"+ document.getElementById("ngay_bd_1").value +"Z";
            console.log(C5);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C5, true);
            xhttp.send();

            var C6 ="Z"+ document.getElementById("ngay_kt_1").value +"X";
            console.log(C6);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C6, true);
            xhttp.send();

            var C7 ="X"+ document.getElementById("list1").value +"C";
            console.log(C7);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C7, true);
            xhttp.send();

            var C8 ="C"+ document.getElementById("time_bom1").value +"V";
            console.log(C8);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C8, true);
            xhttp.send();

            var C9 ="V"+ document.getElementById("ngay_bd_2").value +"B";
            console.log(C9);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C9, true);
            xhttp.send();

            var C10 ="B"+ document.getElementById("ngay_kt_2").value +"N";
            console.log(C10);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C10, true);
            xhttp.send();

            var C11 ="N"+ document.getElementById("list2").value +"M";
            console.log(C11);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C11, true);
            xhttp.send();

            var C12 ="M"+ document.getElementById("time_bom2").value +"Q";
            console.log(C12);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C12, true);
            xhttp.send();

            var C13 ="Q"+ document.getElementById("ngay_bd_3").value +"W";
            console.log(C13);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C13, true);
            xhttp.send();

            var C14 ="W"+ document.getElementById("ngay_kt_3").value +"E";
            console.log(C14);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C14, true);
            xhttp.send();

            var C15 ="E"+ document.getElementById("list3").value +"R";
            console.log(C15);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C15, true);
            xhttp.send();

            var C16 ="R"+ document.getElementById("time_bom3").value +"T";
            console.log(C16);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C16, true);
            xhttp.send();
            break;
        case 2:
            
            document.getElementById("ngay_bd").value = '';
            document.getElementById("ngay_kt").value = '';
            document.getElementById("list").value = '0';
            document.getElementById("time_bom").value = '';

            document.getElementById("ngay_bd_1").value = '';
            document.getElementById("ngay_kt_1").value = '';
            document.getElementById("list1").value = '0';
            document.getElementById("time_bom1").value = '';

            document.getElementById("ngay_bd_2").value = '';
            document.getElementById("ngay_kt_2").value = '';
            document.getElementById("list2").value = '0';
            document.getElementById("time_bom2").value = '';

            document.getElementById("ngay_bd_3").value = '';
            document.getElementById("ngay_kt_3").value = '';
            document.getElementById("list3").value = '0';
            document.getElementById("time_bom3").value = '';

            
            
            
            var C1 ="D"+ 0 +"F";
            console.log(C1);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C1, true);
            xhttp.send();
            

            var C2 = "G"+ 0 +"H";
            console.log(C2);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C2, true);
            xhttp.send();

            var C3 ="J"+ 0 +"K";
            console.log(C3);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C3, true);
            xhttp.send();

            var C4 ="K"+ 0 +"L";
            console.log(C4);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C4, true);
            xhttp.send();

            var C5 ="L"+ 0 +"Z";
            console.log(C5);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C5, true);
            xhttp.send();

            var C6 ="Z"+ 0 +"X";
            console.log(C6);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C6, true);
            xhttp.send();

            var C7 ="X"+ 0 +"C";
            console.log(C7);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C7, true);
            xhttp.send();

            var C8 ="C"+ 0 +"V";
            console.log(C8);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C8, true);
            xhttp.send();

            var C9 ="V"+ 0 +"B";
            console.log(C9);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C9, true);
            xhttp.send();

            var C10 ="B"+ 0 +"N";
            console.log(C10);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C10, true);
            xhttp.send();

            var C11 ="N"+ 0 +"M";
            console.log(C11);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C11, true);
            xhttp.send();

            var C12 ="M"+ 0 +"Q";
            console.log(C12);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C12, true);
            xhttp.send();

            var C13 ="Q"+ 0 +"W";
            console.log(C13);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C13, true);
            xhttp.send();

            var C14 ="W"+ 0 +"E";
            console.log(C14);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C14, true);
            xhttp.send();

            var C15 ="E"+ 0 +"R";
            console.log(C15);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C15, true);
            xhttp.send();

            var C16 ="R"+ 0 +"T";
            console.log(C16);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/Input?Input="+C16, true);
            xhttp.send();
            break;
       
    }

}
//code table
function changeContent()
{
    // ngày bắt đầu công việc 1
    var rn1 = "1";
    var cn1 = "1";
    content1 = document.getElementById("ngay_bd").value;  
    var x1 =document.getElementById('table').rows[parseInt(rn1,10)].cells;
    x1[parseInt(cn1,10)].innerHTML=content1;

    // ngày kết thúc công việc 1
    var rn2 = "1";
    var cn2 = "2";
    content2 = document.getElementById("ngay_kt").value;  
    var x2 =document.getElementById('table').rows[parseInt(rn2,10)].cells;
    x2[parseInt(cn2,10)].innerHTML=content2;

    // giờ bơm công việc 1
    var rn3 = "1";
    var cn3 = "3";
    content3 = document.getElementById("list").value;  
    var x3 =document.getElementById('table').rows[parseInt(rn3,10)].cells;
    x3[parseInt(cn3,10)].innerHTML=content3;

    // thời gian bơm công việc 1
    var rn4 = "1";
    var cn4 = "4";
    content4 = document.getElementById("time_bom").value;  
    var x4 =document.getElementById('table').rows[parseInt(rn4,10)].cells;
    x4[parseInt(cn4,10)].innerHTML=content4;

    // ngày bắt đầu công việc 2
    var rn5 = "2";
    var cn5 = "1";
    content5 = document.getElementById("ngay_bd_1").value;  
    var x5 =document.getElementById('table').rows[parseInt(rn5,10)].cells;
    x5[parseInt(cn5,10)].innerHTML=content5;


    // ngày kết thúc công việc 2
    var rn6 = "2";
    var cn6 = "2";
    content6 = document.getElementById("ngay_kt_1").value;  
    var x6 =document.getElementById('table').rows[parseInt(rn6,10)].cells;
    x6[parseInt(cn6,10)].innerHTML=content6;

    // giờ bơm công việc 2
    var rn7 = "2";
    var cn7 = "3";
    content7 = document.getElementById("list1").value;  
    var x7 =document.getElementById('table').rows[parseInt(rn7,10)].cells;
    x7[parseInt(cn7,10)].innerHTML=content7;


    // thời gian bơm công việc 2
    var rn8 = "2";
    var cn8 = "4";
    content8 = document.getElementById("time_bom1").value;  
    var x8 =document.getElementById('table').rows[parseInt(rn8,10)].cells;
    x8[parseInt(cn8,10)].innerHTML=content8;

    // ngày bắt đầu công việc 3
    var rn9 = "3";
    var cn9 = "1";
    content9 = document.getElementById("ngay_bd_2").value;  
    var x9 =document.getElementById('table').rows[parseInt(rn9,10)].cells;
    x9[parseInt(cn9,10)].innerHTML=content9;



    // ngày kết thúc công việc 3
    var rn10 = "3";
    var cn10 = "2";
    content10 = document.getElementById("ngay_kt_2").value;  
    var x10 =document.getElementById('table').rows[parseInt(rn10,10)].cells;
    x10[parseInt(cn10,10)].innerHTML=content10;


    // giờ bơm công việc 3
    var rn11 = "3";
    var cn11 = "3";
    content11 = document.getElementById("list2").value;  
    var x11 =document.getElementById('table').rows[parseInt(rn11,10)].cells;
    x11[parseInt(cn11,10)].innerHTML=content11;



    // thời gian bơm công việc 3
    var rn12 = "3";
    var cn12 = "4";
    content12 = document.getElementById("time_bom2").value;  
    var x12 =document.getElementById('table').rows[parseInt(rn12,10)].cells;
    x12[parseInt(cn12,10)].innerHTML=content12;

     // ngày bắt đầu công việc 4
     var rn13 = "4";
    var cn13 = "1";
    content13 = document.getElementById("ngay_bd_3").value;  
    var x13 =document.getElementById('table').rows[parseInt(rn13,10)].cells;
    x13[parseInt(cn13,10)].innerHTML=content13;

    // ngày kết thúc công việc 4
    var rn14 = "4";
    var cn14 = "2";
    content14 = document.getElementById("ngay_kt_3").value;  
    var x14 =document.getElementById('table').rows[parseInt(rn14,10)].cells;
    x14[parseInt(cn14,10)].innerHTML=content14;

    // giờ bơm công việc 4
    var rn15 = "4";
    var cn15 = "3";
    content15 = document.getElementById("list3").value;  
    var x15 =document.getElementById('table').rows[parseInt(rn15,10)].cells;
    x15[parseInt(cn15,10)].innerHTML=content15;


    // thời gian bơm công việc 4
    var rn16 = "4";
    var cn16 = "4";
    content16 = document.getElementById("time_bom3").value;  
    var x16 =document.getElementById('table').rows[parseInt(rn16,10)].cells;
    x16[parseInt(cn16,10)].innerHTML=content16;


}


</script>

<body onload="UpdateData()">

</body>
<label>Đồ án tưới cây</label>
<br>
<button id="tttb1" onclick=GetButtonData(1)>OFF</button>
<br>
<button id="tttb2" onclick=GetButtonData(2)>OFF</button>
<br>
<h1>
    Nhiệt độ:
    <label id="nhietdo">0</label>
</h1>

<h1>
    Độ ẩm:
    <label id="doam">0</label>
</h1>

<h1>
    Công việc 1
    Ngày bắt đầu<input type="text" id="ngay_bd">
    Ngày bắt kết thúc<input  type="text" id="ngay_kt">
    Giờ 
        <select id="list">
            <option  value="0">0:00</option>
            <option value="1">1:00</option>
            <option value="2">2:00</option>
            <option value="3">3:00</option>
            <option value="4">4:00</option>
            <option value="5">5:00</option>
            <option value="6">6:00</option>
            <option value="7">7:00</option>
            <option value="8">8:00</option>
            <option value="9">9:00</option>
            <option value="10">10:00</option>
            <option value="11">11:00</option>
            <option value="12">12:00</option>
            <option value="13">13:00</option>
            <option value="14">14:00</option>
            <option value="15">15:00</option>
            <option value="16">16:00</option>
            <option value="17">17:00</option>
            <option value="18">18:00</option>
            <option value="19">19:00</option>
            <option value="20">20:00</option>
            <option value="21">21:00</option>
            <option value="22">22:00</option>
            <option value="23">23:00</option>
        </select>
            
        Thời gian bơm<input id="time_bom">
    </h1>
    <h1>
        Công việc 2
        Ngày bắt đầu<input id="ngay_bd_1">
        Ngày bắt kết thúc<input id="ngay_kt_1">
        Giờ 
            <select id="list1" onchange="getSelectValue();">
                <option value="0">0:00</option>
                <option value="1">1:00</option>
                <option value="2">2:00</option>
                <option value="3">3:00</option>
                <option value="4">4:00</option>
                <option value="5">5:00</option>
                <option value="6">6:00</option>
                <option value="7">7:00</option>
                <option value="8">8:00</option>
                <option value="9">9:00</option>
                <option value="10">10:00</option>
                <option value="11">11:00</option>
                <option value="12">12:00</option>
                <option value="13">13:00</option>
                <option value="14">14:00</option>
                <option value="15">15:00</option>
                <option value="16">16:00</option>
                <option value="17">17:00</option>
                <option value="18">18:00</option>
                <option value="19">19:00</option>
                <option value="20">20:00</option>
                <option value="21">21:00</option>
                <option value="22">22:00</option>
                <option value="23">23:00</option>
            </select>
                
            Thời gian bơm<input id="time_bom1">
    </h1>
    <h1>
        Công việc 3
        Ngày bắt đầu<input id="ngay_bd_2">
        Ngày bắt kết thúc<input id="ngay_kt_2">
        Giờ 
            <select id="list2" onchange="getSelectValue();">
                <option value="0">0:00</option>
                <option value="1">1:00</option>
                <option value="2">2:00</option>
                <option value="3">3:00</option>
                <option value="4">4:00</option>
                <option value="5">5:00</option>
                <option value="6">6:00</option>
                <option value="7">7:00</option>
                <option value="8">8:00</option>
                <option value="9">9:00</option>
                <option value="10">10:00</option>
                <option value="11">11:00</option>
                <option value="12">12:00</option>
                <option value="13">13:00</option>
                <option value="14">14:00</option>
                <option value="15">15:00</option>
                <option value="16">16:00</option>
                <option value="17">17:00</option>
                <option value="18">18:00</option>
                <option value="19">19:00</option>
                <option value="20">20:00</option>
                <option value="21">21:00</option>
                <option value="22">22:00</option>
                <option value="23">23:00</option>
            </select>
                
            Thời gian bơm<input id="time_bom2">
    </h1>
    <h1>
        Công việc 4
        Ngày bắt đầu<input id="ngay_bd_3">
        Ngày bắt kết thúc<input id="ngay_kt_3">
        Giờ 
            <select id="list3" onchange="getSelectValue();">
                <option value="0">0:00</option>
                <option value="1">1:00</option>
                <option value="2">2:00</option>
                <option value="3">3:00</option>
                <option value="4">4:00</option>
                <option value="5">5:00</option>
                <option value="6">6:00</option>
                <option value="7">7:00</option>
                <option value="8">8:00</option>
                <option value="9">9:00</option>
                <option value="10">10:00</option>
                <option value="11">11:00</option>
                <option value="12">12:00</option>
                <option value="13">13:00</option>
                <option value="14">14:00</option>
                <option value="15">15:00</option>
                <option value="16">16:00</option>
                <option value="17">17:00</option>
                <option value="18">18:00</option>
                <option value="19">19:00</option>
                <option value="20">20:00</option>
                <option value="21">21:00</option>
                <option value="22">22:00</option>
                <option value="23">23:00</option>
            </select>
                
            Thời gian bơm<input id="time_bom3">
    </h1>
        <button onclick= GetInPut(1),changeContent()>Lưu</button>
        <button onclick= "GetInPut(2); changeContent()">Hủy quy trình hiện tại</button>
    </h1>
    <h1>
        <table id="table" border="1" cellspacing="0" style="width:70%">
            <tr>
                <th>Công việc</th>
                <th>Ngày bắt đầu</th>
                <th>Ngày kết thúc</th>
                <th>Giờ bơm (giờ)</th>
                <th>Thời gian bơm (phút)</th>
            </tr>
            <tr>
                <td >  1  </td>
                <td >    </td>
                <td >   </td>
                <td >    </td>
                <td >    </td>
            </tr>
            <tr>
                <td >2</td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>   
            <tr>
                <td>3</td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td>4</td>
                <td></td>
                <td></td>
                <td></td>
                <td></td>
            </tr>
        </table>
    </h1>
</html>
)=====";
