export interface Resource {
  id?: string;

  name: string;

  getCost(day: number): number;
}
