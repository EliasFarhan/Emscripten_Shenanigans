mergeInto(LibraryManager.library, 
{
	is_prime_js: function(number)
	{
		if(number < 2)
			return false;
		let n = Math.sqrt(number)
		if(number % 2 == 0)
			return false;
		for(let i = 3; i <= n; i++)
		{
			if(number % i == 0)
				return false;
		}
		return true;
	},
	average_js: function(numbers)
	{
		console.log(typeof numbers);

		console.log(numbers);
		return numbers.reduce((a, b) => a + b) / numbers.length;
	},
});
