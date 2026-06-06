var Solution = function(nums) {
    this.originalArray = [...nums];


    this.currentArray = [...nums];
};


Solution.prototype.reset = function() {
    this.currentArray = [...this.originalArray];


    return this.currentArray;
};


Solution.prototype.shuffle = function() {
    const shuffledArray = [...this.currentArray];


    for (let i = shuffledArray.length - 1; i > 0; i--) {
        const randomIndex = Math.floor(Math.random() * (i + 1));


        [shuffledArray[i], shuffledArray[randomIndex]] = 
        [shuffledArray[randomIndex], shuffledArray[i]];
    }


    return shuffledArray;
};
