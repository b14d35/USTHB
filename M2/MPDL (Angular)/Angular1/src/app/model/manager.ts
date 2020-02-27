import { Worker } from './worker';

export class Manager extends Worker {
  constructor(firstName: string, lastName: string, hourRate: number, private $bonus: number) {
    super(firstName, lastName, hourRate);
  }

  /** implicit polymorphism */
  public getSalary(): number {
    const salary = super.getSalary();
    return salary + this.$bonus;
  }

}
