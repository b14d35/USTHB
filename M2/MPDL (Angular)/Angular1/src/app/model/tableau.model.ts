export class Tableau {
  private $tab1: number[];
  private $tab2: number[];
  constructor() {
    this.$tab1 = [];
    this.$tab2 = [];
  }

  addElement(x: number, value: number) {
    if(value == null){
      return;
    }
    if (x === 1) {
      this.$tab1.push(value);
    } else {
      this.$tab2.push(value);
    }
  }

  private get tab1(): number[] {
    return this.$tab1;
  }

  private get tab2(): number[] {
    return this.$tab2;
  }

  public somme(): number[] {
    const t1 = this.$tab1.length;
    const t2 = this.$tab2.length;
    const tab3 = [];
    for (let i = 0; i < Math.min(t1, t2); i++) {
      tab3.push(this.$tab1[i] + this.$tab2[i]);
    }
    return (t1 > t2) ? tab3.concat(this.$tab1.slice(t2, t1)) : tab3.concat(this.$tab2.slice(t1, t2));
  }
  public soust(): number[] {
    const t1 = this.$tab1.length;
    const t2 = this.$tab2.length;
    const tab3 = [];
    for (let i = 0; i < Math.min(t1, t2); i++) {
      tab3.push(this.$tab1[i] - this.$tab2[i]);
    }
    return (t1 > t2) ? tab3.concat(this.$tab1.slice(t2, t1)) : tab3.concat(this.$tab2.slice(t1, t2).map(x => x * -1));
  }
  public concat(): number[] {
    return this.$tab1.concat(this.$tab2);
  }
  public fusion(): number[] {
    const len1 = this.$tab1.length;
    const len2 = this.$tab2.length;
    const part1 = (len1 % 2 === 0) ? this.$tab1.slice(0, len1 / 2) : this.$tab1.slice(0, (len1 + 1) / 2);
    const part2 = (len2 % 2 === 0) ? this.$tab2.slice(len2 / 2, len2) : this.$tab2.slice((len2 - 1) / 2, len2);
    return part1.concat(part2);
  }
}
