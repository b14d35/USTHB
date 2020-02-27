export class Energy {
  name: string;

  getCost(day: number): number {
    return 1000 * day;
  }
}
