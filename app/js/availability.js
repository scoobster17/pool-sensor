;pool = window.pool || {};
pool.availability = (function(){

	// setup
	var config = {
		delayDuration: 30000,
		indicator: {
			available: "AVAILABLE",
			unavailable: "NOT available"
		}
	};

	// private methods
	var checkAvailability = function() {
		console.log('do ajax call');

		// get elements to update and time
		var availabilityIndicator = document.getElementById('availabilityIndicator');
		var lastCheck = document.getElementById('lastCheck');
		var now = new Date().toString();

		// check if available
		var available = false;

		// update page with availability
		if (available) {
			availabilityIndicator.innerHTML = config.indicator.available;
		} else {
			availabilityIndicator.innerHTML = config.indicator.unavailable;
		}

		// update time last checked
		lastCheck.innerHTML = now;

	};

	// set a delayed check for availability
	var timedCheck = function() {
		setTimeout(function() {
			checkAvailability();
			timedCheck();
		}, config.delayDuration);
	};

	// initialisation function
	var init = function() {

		// check availability on page load
		checkAvailability();

		// call recursive function for repeated timeout for checking availability
		timedCheck();

		// Add event to check availability on click of button
		var checkBtn = document.getElementById('checkBtn');
		checkBtn.addEventListener('click', checkAvailability);

	};

	// public methods
	return {
		checkAvailability: checkAvailability,
		init: init
	};

})();

// call initialisation function
pool.availability.init();

// delete initialisation function
delete pool.availability.init;