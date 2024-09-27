function processData(input) 
{
    // Convert n and k to integers
    var n = parseInt(input.split(' ')[0]);
    var k = parseInt(input.split(' ')[1]);
    var ans = 0;
    
    // Iterate from 1 to n-1
    for(var i = 1; i < n; i++)
    {
        var s = i.toString(); // Convert i to a string

        // Check if the number is a palindrome in base-10
        if(s === s.split('').reverse().join(''))
        {
            // Convert the number to base-k
            var converted = i.toString(k);
            
            // Check if the base-k conversion is a palindrome
            if(converted === converted.split('').reverse().join('')) 
                ans += i; // Add the number to the result if both conditions are met
        }
    }
    
    console.log(ans); // Output the result
} 

// Handling input from stdin
process.stdin.resume();
process.stdin.setEncoding("ascii");
let _input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input); // Process the input once it ends
});
