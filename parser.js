const fs = require('fs')
const app = require('express')();
const bodyParser = require('body-parser');

app.use(bodyParser.json());

app.post('/', (req, res) => {
    const data = req.body;
    tests = [];
    for (test of data["tests"]) {
        tests.push({
            "test": test["input"], 
            "correct_answers": [test["output"].trim()] 
        })
    }
    fs.writeFile('D:\\competitive-programming\\main.cpp__tests', JSON.stringify(tests), function() {});
    res.sendStatus(200);
    console.log("all test cases parsed successfully...");
});

app.listen(12345, err => {
    if (err) {
        console.error(err);
        process.exit(1);
    }
    console.log('Started Listening to Port -> 12345')
});