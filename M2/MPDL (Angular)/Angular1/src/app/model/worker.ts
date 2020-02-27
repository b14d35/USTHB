import { Resource } from './resource';

export class Worker implements Resource {

    name: string;

    /** attributes */
    private $firstName: string;
    private $lastName: string;

    constructor(firstName: string, lastName: string, private $hourRate: number) {
        this.$firstName = firstName;
        this.$lastName = lastName;
    }

    /** methods */
    public changeHourRate(newRate: number): void {
        this.$hourRate = newRate;
    }

    getCost(day: number): number {
        return this.$hourRate * 8 *day;
    }

    public getSalary(): number {
        return this.$hourRate * 160;
    }

    /** properties */
    public get lastName(): string {
        return this.lastName;
    }

    public set lastName(value: string) {

        this.$lastName = value;
    }

    public get firstName(): string {
        return this.firstName;
    }



}
