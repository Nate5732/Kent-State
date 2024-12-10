import { Entity, PrimaryGeneratedColumn, Column } from 'typeorm';

@Entity()
export class Strategy {
  @PrimaryGeneratedColumn()
  id: number;

  @Column()
  userId: number;

  @Column('decimal', { precision: 10, scale: 2 })
  totalIncome: number;

  @Column('decimal', { precision: 10, scale: 2 })
  foodAllocation: number;

  @Column('decimal', { precision: 10, scale: 2 })
  rentAllocation: number;

  @Column('decimal', { precision: 10, scale: 2 })
  billsAllocation: number;

  @Column('decimal', { precision: 10, scale: 2 })
  otherAllocation: number;
}