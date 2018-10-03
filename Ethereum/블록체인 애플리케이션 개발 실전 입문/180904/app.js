// 웹 페이지 서비스 코드
var express = require("express");
var app = express();  
var server = require("http").createServer(app);
var io = require("socket.io")(server);
server.listen(8080);

// 브라우저 접속 시 표시되는 라우팅 코딩
app.use(express.static("public"));
app.get("/", 
    function(req, res)
    {
        res.sendFile(__dirname + "/public/html/index.html");
    }
)

// 배포된 스마트 컨트랙트에 접속하는 코딩

var Web3 = require("web3");
web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));  
var proofContract = web3.eth.contract([{"constant":false,"inputs":[{"name":"fileHash","type":"string"}],"name":"get","outputs":[{"name":"timestamp","type":"uint256"},{"name":"owner","type":"string"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"owner","type":"string"},{"name":"fileHash","type":"string"}],"name":"set","outputs":[],"payable":false,"type":"function"},{"anonymous":false,"inputs":[{"indexed":false,"name":"status","type":"bool"},{"indexed":false,"name":"timestamp","type":"uint256"},{"indexed":false,"name":"owner","type":"string"},{"indexed":false,"name":"fileHash","type":"string"}],"name":"logFileAddedStatus","type":"event"}]);