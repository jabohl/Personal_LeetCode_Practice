var SmallestInfiniteSet = function() {
    this.nextSmallest = 1;


    this.addedBack = new Set();
};


SmallestInfiniteSet.prototype.popSmallest = function() {
    if (this.addedBack.size > 0) {
        const smallest = Math.min(...this.addedBack);


        this.addedBack.delete(smallest);


        return smallest;
    }


    return this.nextSmallest++;
};


SmallestInfiniteSet.prototype.addBack = function(num) {
    if (num < this.nextSmallest) {
        this.addedBack.add(num);
    }
};
